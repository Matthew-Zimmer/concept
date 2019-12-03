#pragma once
#include <type_traits>
namespace Slate
{	
	namespace Imp::Concept
	{
		namespace Satisfies_
		{
			template <typename, typename, typename ...>
			class Satisfies : public std::false_type
			{};

			template <typename Type, typename ... Args>
			class Satisfies<std::void_t<decltype(Type::Test(std::declval<Args>()...))>, Type, Args...> : public std::true_type
			{};
		}
	}

	inline namespace Concept 
	{
		/*
			Constraits:
				Type: Is_Concept<Type> is true
			Summary:
				This will be true or false depending of if the Args... satisfies the concept Type
		*/
		template <typename Type, typename ... Args>
		constexpr bool Satisfies = Imp::Concept::Satisfies_::Satisfies<void, Type, Args...>::value;
	}

	namespace Imp::Concept
	{
		namespace Is_Functor_
		{
			class Is_Functor
			{
			public:
				template <typename Type, typename ... Args>
				static auto Test(Type&& t, Args&& ... args) -> decltype
				(
					t(args...)
				);
			};
		}
		namespace Has_Function_
		{
			class Has_Function
			{
			public:
				template <typename Type, typename Function, typename ... Args>
				static auto Test(Type&& t, Function&& func, Args&& ... args) -> decltype
				(
					func(t, args...)
				);
			};
		}
	}

	inline namespace Concept
	{
		/*
			Summary:
				This will be true or false depending of if the Type is a functor with args Args...
		*/
		template <typename Type, typename ... Args>
		constexpr bool Is_Functor = Satisfies<Imp::Concept::Is_Functor_::Is_Functor, Type, Args...>;

		/*
			Summary:
				This will be true or false depending of if the Type has a function Function with args Args...
		*/
		template <typename Type, typename Function, typename ... Args>
		constexpr bool Has_Function = Satisfies<Imp::Concept::Has_Function_::Has_Function, Type, Function, Args...>;
	}
}