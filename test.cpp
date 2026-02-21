#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE ( "Factorials are computed", "[factorial]") // tag
{
  CHECK( Factorial(0) == 1 ); // assertion
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("checking with +ve n")
  {
		int n=5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 15 );
		REQUIRE(res[random] == v[random]+n);
	}
	SECTION("checking with -ve n")
  {
		int n=-5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 5 );
		REQUIRE(res[random] == v[random]+n);
	}

}

TEST_CASE("splitting a string based on a seperator", "[split]")
{
	std::string test_str = "Hi! - my name is - Ismail.";

	SECTION("splitting with a single character separator")
  {
        std::vector<std::string> res = Split(test_str," ");
		REQUIRE(res.size() == 7);
		REQUIRE( res[0] == "Hi!" );
		REQUIRE( res[res.size()-1] == "Ismail." );
	}
	SECTION("splitting with a multiple character separator")
  {
        std::vector<std::string> res = Split(test_str," - ");
		REQUIRE(res.size() == 3);
		REQUIRE( res[1] == "my name is" );
		REQUIRE( res[res.size()-1] == "Ismail." );
	}
	SECTION("splitting with no character separator")
  {
        std::vector<std::string> res = Split(test_str,"");
		REQUIRE(res.size() == 1);
		REQUIRE( res[0] == test_str );
	}

}

TEST_CASE("remove all substrings", "[RemoveAllSubstrings]")
{
	std::string test_str = "the big tree in the woods.";

	SECTION("remove all occurences of 'the'")
  {
        std::string res = RemoveAllSubstrings(test_str,"the");
		REQUIRE( res == " big tree in  woods." );
	}
	SECTION("remove all occurences of ''")
  {
        std::string res = RemoveAllSubstrings(test_str,"");
		REQUIRE( res == test_str );
	}

}

TEST_CASE("remove first substring", "[RemoveFirstSubstring]")
{
	std::string test_str = "the big tree in the woods.";

	SECTION("remove first occurence of 'the'")
  {
        std::string res = RemoveFirstSubstring(test_str,"the");
		REQUIRE( res == " big tree in the woods." );
	}
	SECTION("remove first occurence of ''")
  {
        std::string res = RemoveFirstSubstring(test_str,"");
		REQUIRE( res == test_str );
	}

}

TEST_CASE("Join strings in a vector with glue", "[join]")
{
	std::vector<std::string> words = {"Hi","my","name","is","Chris!"}; 

	SECTION("Join strings with one character separator")
  {
        std::string res = Join(words," ");
		REQUIRE( res == "Hi my name is Chris!" );
	}
	SECTION("Join strings with multiple character separator")
  {
        std::string res = Join(words,"--");
		REQUIRE( res == "Hi--my--name--is--Chris!" );
	}
	SECTION("Join strings with no separator")
  {
        std::string res = Join(words,"");
		REQUIRE( res == "HimynameisChris!" );
	}

}

TEST_CASE("Match Vectors of integers", "[MatchVectors]")
{
    std::vector<int> a{1,5,2,3,4,5};
    
    

	SECTION("Match vectors a and b.")
  {
        std::vector<int> b{2,5,7,0};
        std::vector<int> res = MatchVectors(a,b);
		REQUIRE( res.size() == 3);
		REQUIRE( res[0] == 1);     
		REQUIRE( res[res.size()-1] == 4);
	}
	SECTION("Match vector a with empty vector")
  {
        std::vector<int> b{};
        std::vector<int> res = MatchVectors(a,b);
		REQUIRE( res.size() == 6);
		REQUIRE( res[0] == 1);     
		REQUIRE( res[res.size()-1] == 5);
	}


}
