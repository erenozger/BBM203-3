#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector> // to get the vector class definition
#define n 3
using std::vector; // to 
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//DD LIST
struct Node_D { 
    string gol_dakika;
    string mac_id;
    string rakip_takim;
    
	struct Node* prev;
	struct Node* next;
};

/*string Gol_Atanlar[10];*/


//LINKED LIST
class Node
{
public:
    Node* next;
    string oyuncu_isim;
    string oyuncu_takim;
    struct Node_D goller;
    
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(string oyuncu_isim,string oyuncu_takim,string rakip_takim,string gol_dakika,string mac_id);
    void print();
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    std::cout << "LIST DELETED";
}

/*bool dup_check(string oyuncu_isim){
	//Listede verilen oyuncunun olup olmadigini kontrol etmek icin bi fonksiyon, false = yok true = var
	bool duplicate_detected = false;
	for(int i=0;i < 10;i++){
		if(Gol_Atanlar[i] == oyuncu_isim){
			duplicate_detected = true;
		}
	}
	return duplicate_detected;
}*/

void LinkedList::add(string oyuncu_isim,string oyuncu_takim,string rakip_takim,string gol_dakika,string mac_id){
    Node* node = new Node();
    /*if(!dup_check(oyuncu_isim)){
    	//Tek gol oldugunda
    	node->goller.prev = this->head;
    	//Tek oldugu icin nexti null olacak
    	node->goller.next = NULL;
	}
    if(dup_check(oyuncu_isim)){
		//Bir cok gol oldugunda
		
	}*/
    node->oyuncu_isim = oyuncu_isim;
    node->oyuncu_takim = oyuncu_takim;
    node->goller.rakip_takim = rakip_takim;
    node->goller.gol_dakika = gol_dakika;
    node->goller.mac_id = mac_id;
    /*//for debug-----
    cout << "Goller Node Prev : " << node->goller.prev << endl;
    cout << "Oyuncu Listesindeki Adresi : " << this->head << endl;
    //-----*/
	node->next = this->head;
    this->head = node;
    this->length++;
    
}

void LinkedList::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->oyuncu_isim << "," << head->oyuncu_takim << std::endl;
        head = head->next;
        i++;
    }
}

int main(int argc, char *argv[]) {

	LinkedList* list = new LinkedList();
	int counter = 0;
	ifstream infile(argv[1]);
	if(!infile.is_open()){
		cout << "Belgeyi acmadi" <<endl;
		return 0;
	}
	

	string my_string;
	string line;
	int sayac = 0;
	int firsthalf = 0;
	int secondhalf = 0;
	while(getline(infile,line)){
		string ilk_item,ikinci_item,ucuncu_item,dorduncu_item,besinci_item;
		
		stringstream ss(line);
		
		getline(ss,ilk_item,',');
		getline(ss,ikinci_item,',');
		getline(ss,ucuncu_item,',');
		getline(ss,dorduncu_item,',');
		getline(ss,besinci_item,',');
		int score = stoi(besinci_item);

		if (score>45){
			secondhalf = secondhalf + 1;
		}else firsthalf = secondhalf + 1;



		if(!ilk_item.empty()){
			list->add(ilk_item,ikinci_item,ucuncu_item,dorduncu_item,besinci_item);
			/*for(int i=0;i < 10;i++){
				if(!dup_check(ilk_item)){
					//Duplicate olmadan gol atanlari listeye atiyor
					Gol_Atanlar[sayac] = ilk_item;
					//Arrayin sayaci, arttiralim ki farkli yerlere yazsin
					sayac++;
				}
			}*/


		}
	}
	
	FILE *output_file = fopen(argv[3],"w");
	  if (output_file!=NULL)
  	{
    
    fclose (output_file);
	}
	/*if(!out.is_open()){
		cout << "Belgeyi acmadi" <<endl;
		return 0;
	}*/
	if (firsthalf > secondhalf){
		int a = 0;
		fprintf(output_file,"1)THE MOST SCORED HALF %d ",a);
	}
	if (secondhalf > firsthalf){
		int b = 1;
		fprintf(output_file,"1)THE MOST SCORED HALF %d",b);
	}
	else {
		int c;
		c = -1;
		fprintf(output_file,"1)THE MOST SCORED HALF %d",c);
	}
	
		
	
	list->print();
	infile.close();
	
	return 0;
}
