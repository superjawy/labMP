//Задача №112984. Гоблины и шаманы

//Гоблины Мглистых гор очень любях ходить к своим шаманам. Так как гоблинов много, к шаманам часто образуются очень длинные очереди. А поскольку много гоблинов в одном месте быстро образуют шумную толку, которая мешает шаманам проводить сложные медицинские манипуляции, последние решили установить некоторые правила касательно порядка в очереди.

//Обычные гоблины при посещении шаманов должны вставать в конец очереди. Привилегированные же гоблины, знающие особый пароль, встают ровно в ее середину, причем при нечетной длине очереди они встают сразу за центром.

//Так как гоблины также широко известны своим непочтительным отношением ко всяческим правилам и законам, шаманы попросили вас написать программу, которая бы отслеживала порядок гоблинов в очереди.

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int inquiries;
    cin >> inquiries;
    
    deque<int>inquiries_list,inquiries_list2;
    
    for(int count = 0; count < inquiries; ++count){
        char sign;
        cin >> sign;
        
        if(sign == '+'){
            int i;
            cin >> i;
            
            inquiries_list.push_back(i);
            
            if(inquiries_list.size() > inquiries_list2.size()){
                inquiries_list2.push_back(inquiries_list.front());
                inquiries_list.pop_front();
            }
        }
        
        else if(sign == '*'){
            int i;
            cin >> i;
            
            inquiries_list.push_front(i);
            
            if(inquiries_list.size() > inquiries_list2.size()){
                inquiries_list2.push_back(inquiries_list.front());
                inquiries_list.pop_front();
            }
        }
        else{
            cout << inquiries_list2.front() << "\n";
            
            inquiries_list2.pop_front();
            
            if(inquiries_list.size() > inquiries_list2.size()){
                inquiries_list2.push_back(inquiries_list.front());
                inquiries_list.pop_front();
            }
        }
    }
    return 0;
}
