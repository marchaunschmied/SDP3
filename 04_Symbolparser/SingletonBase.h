///////////////////////////////////////////////////////////////////////////
// Workfile :		SingletonBase.h
// Author :			Markus Riegler
// Date :			22-November-2019
// Description :	Template Class for Singleton
// Revision :		1
///////////////////////////////////////////////////////////////////////////

#ifndef SINGLETONBASE_H
#define SINGLETONBASE_H

#include <memory>
#include <utility>

//template singleton base class
template<typename T> class SingletonBase {
public:
	template<typename ...Args> static T& GetInstance(Args... args) {
		if (mInstance == nullptr)
		{
			mInstance = std::unique_ptr<T>{ new T(std::forward<Args>(args)...) };
		}
		return *mInstance;
	}

	//free singleton before end of program
	static void Delete() { mInstance.reset(); }

protected:
	SingletonBase() = default;

private:
	SingletonBase(SingletonBase const& s) = delete;
	SingletonBase& operator= (SingletonBase const& s) = delete;

	static std::unique_ptr<T> mInstance;
};

//init static member
template <typename T> std::unique_ptr<T> SingletonBase<T>::mInstance{ nullptr };

#endif

