﻿/*
NowCoder每天要给许多客户写电子邮件。
正如你所知，如果一封邮件中包含多个收件人，
收件人姓名之间会用一个逗号和空格隔开；
如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
现在给你一组收件人姓名，请你帮他生成相应的收件人列表。*/
 #include <iostream> 
 #include <string> 
 #include <cstdio>
 
 int main()
 {    
	int n;
    while(std::cin >> n) 
	 //接收数字
    {
	        std::cin.get(); 
	 //处理回车
	        std::string name;
	        for(int i=0; i < n; i++)
		 //名字分别处理
	        {
				bool quote = false;
				std::getline(std::cin, name);
				if (name.ﬁnd(',') != std::string::npos || name.ﬁnd(' ') != std::string::npos) //找到逗号或者空格，就要加双引号  
				{
					quote = true;
				}                        
				if (quote)            
				{                
					putchar('\"');
					//putchar效率更高
				}
				std::cout << name;
				if (quote)
	           	{
					putchar('\"');
				}  
				if (i == n - 1)
					//如果已经是最后一个字符串，那就补回车，否则加逗号和空格
				{
					putchar('\n');
				}
				else
				{
					putchar(',');
					putchar(' ');
				} 
	       }    
	}    
	return 0;
}

 