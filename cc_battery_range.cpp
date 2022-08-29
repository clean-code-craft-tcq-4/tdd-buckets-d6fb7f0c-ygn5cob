#include "cc_battery_range.hpp"

void print_Output(std::map<std::string, int>OutputMap){
   std::cout<<"Ampere, Readings"<<std::endl;
   for(auto x: OutputMap){
      std::cout << x.first << "   " << x.second <<std::endl;
   }
}

std::map<std::string, int> detectampRanges(std::vector<int> samples){
	sort(samples.begin(), samples.end());
	int count = 1;
    std::string str="";
	std::map<std::string, int>OutputMap{};
    for (int i = 0; i < samples.size(); i++){
        if((i+1)!=samples.size() && samples[i]+1 >= (samples[i+1])){
            if(count == 1){
             str =std::to_string(samples[i]);   
            }
          count++;
        }
        else{
           str +="-" + std::to_string(samples[i]);
           OutputMap[str] =  count;
           count=1;
        }
	}
	print_Output(OutputMap);	
	return OutputMap;
}
std::vector<std::string> ampRanges(std::vector<int> samples)
{
	std::vector<std::string> returnrangeList {};
	std::map<std::string, int>matadatamap = detectampRanges(samples);
	
	for(auto x: matadatamap){
		std::string metadata = x.first + ", " + std::to_string(x.second);
		returnrangeList.push_back(metadata);
	}
	
	matadatamap.clear();
	return returnrangeList;
}