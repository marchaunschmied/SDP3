///////////////////////////////////////////////////////////////////////////
// Workfile :		FileSystem.cpp
// Author :			Marc Haunschmied
// Date :			16-December-2019
// Description :	Test class for filesystem implementation
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "FileSystem.h"
#include "DumpVisitor.h"

/////////////////////////////////////////////////
// sets up a complete linux filesystem
/////////////////////////////////////////////////
void FileSystem::Test() {
	NodeFactory fact;

	Folder::SPtr root = fact.CreateFolder("/");
	mRoot = root;

	Folder::SPtr bin = fact.CreateFolder("bin");
	Folder::SPtr boot = fact.CreateFolder("boot");
	Folder::SPtr dev = fact.CreateFolder("dev");
	Folder::SPtr etc = fact.CreateFolder("etc");
	Folder::SPtr home = fact.CreateFolder("home");
	Folder::SPtr lib = fact.CreateFolder("lib");
	Folder::SPtr media = fact.CreateFolder("media");
	Folder::SPtr mnt = fact.CreateFolder("mnt");

	root->Add(bin);
	root->Add(boot);
	root->Add(dev);
	root->Add(etc);
	root->Add(home);
	root->Add(lib);
	root->Add(media);
	root->Add(mnt);

	File::SPtr bash = fact.CreateFile("bash", 32, 256);
	File::SPtr bzip2 = fact.CreateFile("bzip2", 32, 256);
	File::SPtr grep = fact.CreateFile("grep", 32, 256);
	File::SPtr systemd = fact.CreateFile("systemd", 32, 256);

	bash->Write(1234);
	bzip2->Write(1956);
	grep->Write(21004);
	systemd->Write(5234);

	bin->Add(bash);
	bin->Add(bzip2);
	bin->Add(grep);
	bin->Add(systemd);

	Folder::SPtr grub = fact.CreateFolder("grub");
	File::SPtr grubcfg = fact.CreateFile("grub.cfg", 32, 16);
	grubcfg->Write(144);
	grub->Add(grubcfg);
	boot->Add(grub);

	File::SPtr memtest = fact.CreateFile("memtest86.bin", 32, 16384);
	File::SPtr vmlinux = fact.CreateFile("vmlinux.bin", 32, 65536);
	memtest->Write(255000);
	vmlinux->Write(1420690);
	boot->Add(memtest);
	boot->Add(vmlinux);

	//filesize 0
	dev->Add(fact.CreateFile("tty0", 32, 16));
	dev->Add(fact.CreateFile("tty1", 32, 16));
	dev->Add(fact.CreateFile("tty2", 32, 16));
	dev->Add(fact.CreateFile("tty3", 32, 16));
	dev->Add(fact.CreateFile("tty4", 32, 16));
	dev->Add(fact.CreateFile("tty5", 32, 16));
	File::SPtr tty6 = fact.CreateFile("tty6", 32, 16);
	tty6->Write(64);
	dev->Add(tty6);

	Folder::SPtr acpi = fact.CreateFolder("acpi");
	Folder::SPtr bluetooth = fact.CreateFolder("bluetooth");
	Folder::SPtr emacs = fact.CreateFolder("emacs");
	Folder::SPtr initd = fact.CreateFolder("initd");
	Folder::SPtr modprobe = fact.CreateFolder("modprobe");
	Folder::SPtr kernel = fact.CreateFolder("kernel");
	Folder::SPtr mysql = fact.CreateFolder("mysql");
	Folder::SPtr systemd_f = fact.CreateFolder("systemd");

	etc->Add(acpi);
	etc->Add(bluetooth);
	etc->Add(emacs);
	etc->Add(initd);
	etc->Add(modprobe);
	etc->Add(kernel);
	etc->Add(mysql);
	etc->Add(systemd_f);

	File::SPtr asus_wireless = fact.CreateFile("asus-wireless.sh", 32, 512);
	asus_wireless->Write(1000);
	acpi->Add(asus_wireless);

	Folder::SPtr events = fact.CreateFolder("events");
	File::SPtr asus_wireless_on = fact.CreateFile("asus-wireless-on", 32, 1024);
	asus_wireless_on->Write(3333);
	events->Add(asus_wireless_on);
	acpi->Add(events);

	Folder::SPtr bsy3 = fact.CreateFolder("bsy3");
	home->Add(bsy3);

	Folder::SPtr dok = fact.CreateFolder("Dokumente");
	bsy3->Add(dok);

	Folder::SPtr scan = fact.CreateFolder("Scans");
	dok->Add(scan);
	Folder::SPtr pdfs = fact.CreateFolder("PDFs");
	dok->Add(pdfs);
	Folder::SPtr zahlung = fact.CreateFolder("Zahlungen");
	dok->Add(zahlung);
	Folder::SPtr sauf = fact.CreateFolder("Saufen");
	zahlung->Add(sauf);

	Folder::SPtr down = fact.CreateFolder("Downloads");
	bsy3->Add(down);
	Folder::SPtr pics = fact.CreateFolder("Bilder");
	bsy3->Add(pics);
	Folder::SPtr workspace = fact.CreateFolder("Workspace");
	bsy3->Add(workspace);

	Folder::SPtr codeblocks = fact.CreateFolder("code_blocks");
	workspace->Add(codeblocks);
	Folder::SPtr interp = fact.CreateFolder("CommandoInterpreter");
	codeblocks->Add(interp);
	Folder::SPtr int_bin = fact.CreateFolder("bin");
	interp->Add(int_bin);
	Folder::SPtr int_obj = fact.CreateFolder("obj");
	interp->Add(int_obj);

	File::SPtr main = fact.CreateFile("main.c", 32, 2048);
	main->Write(55000);
	interp->Add(main);

	File::SPtr prog_bin = fact.CreateFile("prog.bin", 32, 5120);
	prog_bin->Write(89120);
	int_bin->Add(prog_bin);

	File::SPtr main_o = fact.CreateFile("main.o", 32, 2048);
	main_o->Write(55000);
	int_obj->Add(main_o);

	//create some links
	Link::SPtr code = fact.CreateLink("sourcecode", main);
	bsy3->Add(code);
	workspace->Add(fact.CreateLink("search_programm", grep));
	dok->Add(fact.CreateLink("activate_wifi", asus_wireless_on));
	dok->Add(fact.CreateLink("start", etc));
	dok->Add(fact.CreateLink("codebase", code));

	//testing if visitors work on non root element
	DumpVisitor dVis;
	std::cout << "Home:" << std::endl;
	home->Accept(dVis);

	//test removing folder
	bsy3->Remove(pics);

	//after removing
	std::cout << "Home after removing :" << std::endl << std::endl;
	home->Accept(dVis);

	//test indexed access
	std::cout << "indexed access: " << std::endl << std::endl;
	std::cout << bsy3->GetChild(1)->GetName() << std::endl << std::endl ;

	//self assignment
	try {
		Folder::SPtr test = fact.CreateFolder("test");
		test->Add(test);
	}
	catch (std::string & s) {
		std::cerr << s << std::endl;
	}
}


FileSystem::FileSystem(){
	Test();
}

void FileSystem::Visit(NodeVisitor& visitor){
	mRoot->Accept(visitor);
}
