//#include "../src/main.cpp"
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
//
//TEST_CASE("Normal Test Case", "[norm]") {
//	AdjacencyList graph;
//	graph.AddWebpage("a.com", "b.com");
//	graph.AddWebpage("c.com", "e.com");
//	graph.AddWebpage("e.com", "b.com");
//	graph.AddWebpage("d.com", "a.com");
//	graph.AddWebpage("a.com", "c.com");
//	graph.AddWebpage("b.com", "e.com");
//	graph.AddWebpage("c.com", "d.com");
//
//	std::vector<double> actualOutput = graph.Testing(2);  
//	std::vector<double> expectedOutput = {0.20, 0.30, 0.10, 0.10, 0.30};
//	REQUIRE(actualOutput.size() == expectedOutput.size());
//	REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Single Webpage", "[single]") {
//	AdjacencyList graph; 
//	graph.AddWebpage("a.com", "a.com");
//
//	std::vector<double> actualOutput = graph.Testing(2);  
//	std::vector<double> expectedOutput = {1.00};
//	REQUIRE(actualOutput.size() == expectedOutput.size());
//	REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Add Duplicate", "[duplicate]") {
//	AdjacencyList graph; 
//	graph.AddWebpage("a.com", "b.com"); 
//	graph.AddWebpage("b.com", "c.com");
//	graph.AddWebpage("b.com", "c.com");
//	graph.AddWebpage("d.com", "a.com"); 
//	graph.AddWebpage("a.com", "c.com"); 
//	graph.AddWebpage("b.com", "e.com"); 
//	graph.AddWebpage("c.com", "d.com"); 
//	graph.AddWebpage("a.com", "f.com");
//	graph.AddWebpage("f.com", "e.com");
//	graph.AddWebpage("f.com", "b.com"); 
//	graph.AddWebpage("c.com", "f.com"); 
//	graph.AddWebpage("d.com", "e.com");
//
//
//	std::vector<double> actualOutput = graph.Testing(5); 
//	std::vector<double> expectedOutput = { 0.02, 0.04, 0.04, 0.03, 0.09, 0.04 };
//	REQUIRE(actualOutput.size() == expectedOutput.size());
//	REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Test Many Inputs", "[loop]") {
//	AdjacencyList graph; 
//	graph.AddWebpage("a.com", "b.com"); 
//	graph.AddWebpage("a.com", "h.com"); 
//	graph.AddWebpage("a.com", "m.com"); 
//	graph.AddWebpage("b.com", "o.com"); 
//	graph.AddWebpage("b.com", "c.com"); 
//	graph.AddWebpage("b.com", "d.com"); 
//	graph.AddWebpage("c.com", "a.com"); 
//	graph.AddWebpage("c.com", "f.com"); 
//	graph.AddWebpage("c.com", "d.com"); 
//	graph.AddWebpage("d.com", "f.com"); 
//	graph.AddWebpage("e.com", "b.com"); 
//	graph.AddWebpage("e.com", "d.com"); 
//	graph.AddWebpage("e.com", "i.com");
//	graph.AddWebpage("g.com", "k.com"); 
//	graph.AddWebpage("g.com", "h.com");
//	graph.AddWebpage("g.com", "c.com");
//	graph.AddWebpage("g.com", "a.com");
//	graph.AddWebpage("h.com", "m.com");
//	graph.AddWebpage("h.com", "k.com");
//	graph.AddWebpage("i.com", "j.com");
//	graph.AddWebpage("i.com", "p.com");
//	graph.AddWebpage("i.com", "b.com");
//	graph.AddWebpage("j.com", "f.com");
//	graph.AddWebpage("j.com", "p.com");
//	graph.AddWebpage("j.com", "b.com");
//	graph.AddWebpage("k.com", "f.com");
//	graph.AddWebpage("k.com", "c.com");
//	graph.AddWebpage("l.com", "k.com");
//	graph.AddWebpage("l.com", "r.com");
//	graph.AddWebpage("l.com", "n.com");
//	graph.AddWebpage("l.com", "b.com");
//	graph.AddWebpage("l.com", "j.com");
//	graph.AddWebpage("m.com", "k.com");
//	graph.AddWebpage("m.com", "q.com");
//	graph.AddWebpage("n.com", "m.com");
//	graph.AddWebpage("o.com", "a.com");
//	graph.AddWebpage("o.com", "b.com");
//	graph.AddWebpage("p.com", "n.com");
//	graph.AddWebpage("p.com", "e.com");
//	graph.AddWebpage("q.com", "n.com");
//	graph.AddWebpage("q.com", "h.com");
//	graph.AddWebpage("r.com", "k.com");
//	graph.AddWebpage("r.com", "m.com");
//
//	std::vector<double> actualOutput = graph.Testing(2); 
//	std::vector<double> expectedOutput = { 0.06, 0.11, 0.06, 0.06, 0.03, 0.12, 0.00, 0.06, 0.20, 0.03, 0.11, 0.00, 0.13, 0.07, 0.02, 0.04, 0.03, 0.01 };
//	std::sort(expectedOutput.begin(), expectedOutput.end());
//	REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Test Many Power Iterations", "[loop]") {
//	AdjacencyList graph;
//	graph.AddWebpage("a.com", "b.com");
//	graph.AddWebpage("a.com", "d.com");
//	graph.AddWebpage("b.com", "c.com");
//	graph.AddWebpage("c.com", "d.com");
//	graph.AddWebpage("d.com", "b.com");
//	graph.AddWebpage("d.com", "c.com");
//
//	std::vector<double> actualOutput = graph.Testing(25);
//	std::vector<double> expectedOutput = { 0.00, 0.20, 0.40, 0.40 }; 
//	std::sort(expectedOutput.begin(), expectedOutput.end());
//	REQUIRE(actualOutput == expectedOutput);
//}