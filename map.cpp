#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cwchar>
#include <windows.h>
#include<ctime>
using namespace std;
#define size 18
#include "map.h"
int city[size][size]={  {0,5,0,0,0,0,0,0,0,13,0,0,0,0,11,0,0,0},       //1
                        {5,0,6,4,0,0,0,0,0,0,0,4,0,0,0,0,0,0},      //2
                        {0,6,0,0,0,6,0,0,0,0,0,0,5,0,0,0,0,0},      //3
                        {0,4,0,0,4,0,0,0,0,0,0,0,0,0,4,0,0,0},      //4
                        {0,0,0,4,0,0,0,0,0,0,0,0,4,0,0,6,0,0},      //5
                        {0,0,6,0,0,0,5,0,0,0,0,0,0,0,0,0,5,0},      //6
                        {0,0,0,0,0,5,0,2,0,0,0,0,0,0,0,5,0,0},      //7
                        {0,0,0,0,0,0,2,0,3,0,0,0,0,6,0,0,0,4},      //8
                        {0,0,0,0,0,0,0,3,0,0,0,0,0,0,6,0,4,0},      //9
                        {13,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0},     //10
                        {0,0,0,0,0,0,0,0,0,2,0,3,5,0,0,0,0,0},      //11
                        {0,4,0,0,0,0,0,0,0,0,3,0,0,7,0,0,0,0},      //12
                        {0,0,5,0,4,0,0,0,0,0,5,0,0,3,0,0,0,0},      //13
                        {0,0,0,0,0,0,0,6,0,0,0,7,3,0,1,5,8,0},      //14
                        {0,0,0,4,0,0,0,0,6,0,0,0,0,1,0,0,0,0},      //15
                        {11,0,0,0,6,0,5,0,0,0,0,0,0,5,0,0,0,0},     //16
                        {0,0,0,0,0,5,0,0,4,0,0,0,0,8,0,0,0,0},      //17
                        {0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,2,0}}; 
                        
                        
int map[size][size]={   {0,2,0,0,0,0,0,0,0,4,0,0,0,0,4,0,0,0},       //1
                        {2,0,3,1,0,0,0,0,0,0,0,4,0,0,0,0,0,0},      //2
                        {0,3,0,0,0,3,0,0,0,0,0,0,5,0,0,0,0,0},      //3
                        {0,1,0,0,1,0,0,0,0,0,0,0,0,0,4,0,0,0},      //4
                        {0,0,0,1,0,0,0,0,0,0,0,0,4,0,0,6,0,0},      //5
                        {0,0,3,0,0,0,2,0,0,0,0,0,0,0,0,0,5,0},      //6
                        {0,0,0,0,0,2,0,1,0,0,0,0,0,0,0,5,0,0},      //7
                        {0,0,0,0,0,0,1,0,3,0,0,0,0,6,0,0,0,4},      //8
                        {0,0,0,0,0,0,0,3,0,0,0,0,0,0,6,0,4,0},      //9
                        {4,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0},     //10
                        {0,0,0,0,0,0,0,0,0,2,0,3,1,0,0,0,0,0},      //11
                        {0,4,0,0,0,0,0,0,0,0,3,0,0,4,0,0,0,0},      //12
                        {0,0,5,0,4,0,0,0,0,0,1,0,0,3,0,0,0,0},      //13
                        {0,0,0,0,0,0,0,6,0,0,0,4,3,0,1,5,2,0},      //14
                        {0,0,0,4,0,0,0,0,6,0,0,0,0,1,0,0,0,0},      //15
                        {4,0,0,0,6,0,5,0,0,0,0,0,0,5,0,0,0,0},     //16
                        {0,0,0,0,0,5,0,0,4,0,0,0,0,2,0,0,0,0},      //17
                        {0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,2,0}};     //18
void mapping::parent_path(int i, int parent[]){
	 if(i==-1)
        {
            return;
        }
        parent_path(parent[i], parent);
        cout<<i<<"->";
}
void mapping::display(int source, int destination, int distance[], int parent[]){
	system("cls");
	  if(destination!=source)
        {
        	cout<<"\n---------Booking Details---------\n\n";
            time_t timetoday;
            time (&timetoday);
            cout<<"Booking Date n Time: "<< asctime(localtime(&timetoday));
            bill=billing(distance,destination);
            int time=time_hour(distance,destination);
            cout<<"Location: ";
            cout<<source<<" to ";
            cout<<destination<<endl;
            cout<<"Distance: ";
            cout<<distance[destination]<<"km"<<endl;
            cout<<"Path: ";
            parent_path(destination,parent);
            cout<<endl;
        }
        else
        if(destination==source)
        {
            cout<<"You are already at your Destination. Thankyou."<<endl;
        }
}
void mapping::dijkstra(int map[size][size], int source, int destination){
	    int distance[size];
        bool visited[size];
        int parent[size];
        for(int i=0;i<size;i++) 
        {
            parent[0]=-1;
            distance[i]=INT_MAX;
            visited[i]=false;
        }
        distance[source]=0;
        parent[source]=-1;
        for(int i=1;i<size;i++)
        {
            int next=-1;
            int dis=INT_MAX;
            for (int j=0;j<size;j++)
            {
                if (!visited[j] && distance[j]<dis) 
                {
                    next=j;
                    dis=distance[j];
                }
            }
            visited[next]=true;
            for (int j=0;j<size;j++)
            {
                int map_dis=map[next][j];
                if(map_dis>0 && ((dis+map_dis)<distance[j]))
                {
                    parent[j]=next;
                    distance[j]=dis+map_dis;
                }
            }
        }
        display(source,destination,distance,parent);
}
int mapping::sourceinput(){
	stop_names();
        cout<<endl;
        string source_name;
        int source;
        pos1:
        lable2:
        cout<<"Enter Name of the stop are you at: "<<endl;
        fflush(stdin);
        getline(cin,source_name);
        
        if(source_name=="corner" || source_name=="CORNER")
        {
            source=0;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="bus stop1" || source_name=="BUS STOP1")
        {
            source=1;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="park" || source_name=="PARK")
        {
            source=2;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="station" || source_name=="STATION")
        {
            source=3;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="mall" || source_name=="MALL")
        {
            source=4;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="gym" || source_name=="GYM")
        {
            source=5;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="bus stop2" || source_name=="BUS STOP2")
        {
            source=6;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="hospital" || source_name=="HOSPITAL")
        {
            source=7;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="hostel" || source_name=="HOSTEL")
        {
            source=8;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="hotel" || source_name=="HOTEL")
        {
            source=9;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="bus stop3" || source_name=="BUS STOP3")
        {
            source=10;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="university road" || source_name=="UNIVERSITY ROAD")
        {
            source=11;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="college road" || source_name=="COLLEGE ROAD")
        {
            source=12;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="food street" || source_name=="FOOD STREET")
        {
            source=13;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="bus stop4" || source_name=="BUS STOP4")
        {
            source=14;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="school" || source_name=="SCHOOL")
        {
            source=15;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="mosque" || source_name=="MOSQUE")
        {
            source=16;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="airport" || source_name=="AIRPORT")
        {
            source=17;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        {
            cout<<"Enter valid source."<<endl;
            goto lable2;
        }
        return source;
}
int mapping::destinationinput(){
	string destination_name;
        int destination;
        pos1:
        lable1:
        cout<<"Enter Name of the stop you want to go: "<<endl;
        fflush(stdin);
        getline(cin,destination_name);
        if(destination_name=="corner" || destination_name=="CORNER")
        {
            destination=0;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="bus stop1" || destination_name=="BUS STOP1")
        {
            destination=1;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="park" || destination_name=="PARK")
        {
            destination=2;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="station" || destination_name=="STATION")
        {
            destination=3;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="mall" || destination_name=="MALL")
        {
            destination=4;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="gym" || destination_name=="GYM")
        {
            destination=5;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="bus stop2" || destination_name=="BUS STOP2")
        {
            destination=6;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="hospital" || destination_name=="HOSPITAL")
        {
            destination=7;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="hostel" || destination_name=="HOSTEL")
        {
            destination=8;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="hotel" || destination_name=="HOTEL")
        {
            destination=9;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="bus stop3" || destination_name=="BUS STOP3")
        {
            destination=10;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="university road" || destination_name=="UNIVERSITY ROAD")
        {
            destination=11;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="college road" || destination_name=="COLLEGE ROAD")
        {
            destination=12;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="food street" || destination_name=="FOOD STREET")
        {
            destination=13;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="bus stop4" || destination_name=="BUS STOP4")
        {
            destination=14;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="school" || destination_name=="SCHOOL")
        {
            destination=15;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="mosque" || destination_name=="MOSQUE")
        {
            destination=16;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="airport" || destination_name=="AIRPORT")
        {
            destination=17;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        {
            cout<<"Enter valid destination."<<endl;
            goto lable1;
        }
        return destination;
}
void mapping::stop_names(){
		cout<< "Corner          : stop 0"<<endl;
        cout<< "bus stop1       : stop 1"<<endl;
        cout<< "park            : stop 2"<<endl;
        cout<< "station         : stop 3"<<endl;
        cout<< "mall            : stop 4"<<endl;
		cout<< "gym             : stop 5"<<endl;
        cout<< "bus stop2       : stop 6"<<endl;
        cout<< "hospital        : stop 7"<<endl;
        cout<< "hostel          : stop 8"<<endl;
        cout<< "hotel           : stop 9"<<endl;
        cout<< "bus stop3       : stop 10"<<endl;
        cout<< "university road : stop 11"<<endl;
        cout<< "college road    : stop 12"<<endl;
        cout<< "food street     : stop 13"<<endl;
        cout<< "bus stop4       : stop 14"<<endl;
        cout<< "school          : stop 15"<<endl;
        cout<< "mosque stop1    : stop 16"<<endl;
        cout<< "airport         : stop 17"<<endl;
}
int mapping::time_hour(int distance[], int destination){
	int time;
        int hour=0;
        time=time_taken(distance,destination);
        while(time>60)
        {
            if(time>=60)
            {
                time=time-60;
                hour++; 
            }
        }
        cout<<endl;
        cout<<"Astimate time:  ";
        cout<<hour<<" hours and "<<time<<" minutes"<<endl;
}
int mapping::time_taken(int distance[], int destination){
	 int time_per_km=10;
        time_per_km=time_per_km*distance[destination];
        return time_per_km;
}
float mapping::billing(int distance[], int destination){
	 int amount_per_min=15;
        int time=time_taken(distance, destination);
        return amount_per_min*time;
}
void mapping::take_route(){
	int s=sourceinput();
	int d=destinationinput();
	dijkstra(map, s, d);
}
int mapping::citysource(){
	city_names();
        cout<<endl;
        
        int source;
        pos1:
        lable2:
        cout<<"Enter Name of the city you are at: "<<endl;
        fflush(stdin);
        getline(cin,source_name);
        
        if(source_name=="tokyo" || source_name=="TOKYO")
        {
            source=0;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="sapporo" || source_name=="SAPPORO")
        {
            source=1;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="kyoto" || source_name=="KYOTO")
        {
            source=2;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="hiroshima" || source_name=="HIROSHIMA")
        {
            source=3;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="fukuoka" || source_name=="FUKUOKA")
        {
            source=4;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="osaka" || source_name=="OSAKA")
        {
            source=5;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="nagasaki" || source_name=="NAGASAKI")
        {
            source=6;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="sendai" || source_name=="SENDAI")
        {
            source=7;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="matsue" || source_name=="MATSUE")
        {
            source=8;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="shizuoka" || source_name=="SHIZUOKA")
        {
            source=9;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="otsu" || source_name=="OTSU")
        {
            source=10;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="sagamihara" || source_name=="SAGAMIHARA")
        {
            source=11;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="gifu" || source_name=="GIFU")
        {
            source=12;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="matsumoto" || source_name=="MATSUMOTO")
        {
            source=13;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="sakai" || source_name=="SAKAI")
        {
            source=14;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="kofu" || source_name=="KOFU")
        {
            source=15;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="yamagata" || source_name=="YAMAGATA")
        {
            source=16;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        if(source_name=="kurashiki" || source_name=="KURASHIKI")
        {
            source=17;
            if(source>size)
            {
                goto pos1;
            }
        }
        else
        {
            cout<<"Enter valid source."<<endl;
            goto lable2;
        }
        return source;
}
int mapping::citydestination(){
	
        int destination;
        pos1:
        lable1:
        cout<<"Enter Name of the city you want to go: "<<endl;
        fflush(stdin);
        getline(cin,destination_name);
        if(destination_name=="tokyo" || destination_name=="TOKYO")
        {
            destination=0;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="sapporo" || destination_name=="SAPPORO")
        {
            destination=1;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="kyoto" || destination_name=="KYOTO")
        {
            destination=2;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="hiroshima" || destination_name=="HIROSHIMA")
        {
            destination=3;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="fukuoka" || destination_name=="FUKUOKA")
        {
            destination=4;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="osaka" || destination_name=="OSAKA")
        {
            destination=5;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="nagasaki" || destination_name=="NAGASAKI")
        {
            destination=6;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="sendai" || destination_name=="SENDAI")
        {
            destination=7;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="matsue" || destination_name=="MATSUE")
        {
            destination=8;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="shizuoka" || destination_name=="SHIZUOKA")
        {
            destination=9;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="otsu" || destination_name=="OTSU")
        {
            destination=10;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="sagamihara" || destination_name=="SAGAMIHARA")
        {
            destination=11;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="GIFU" || destination_name=="gifu")
        {
            destination=12;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="matsumoto" || destination_name=="MATSUMOTO")
        {
            destination=13;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="sakai" || destination_name=="SAKAI")
        {
            destination=14;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="kofu" || destination_name=="KOFU")
        {
            destination=15;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="yamagata" || destination_name=="YAMAGATA")
        {
            destination=16;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        if(destination_name=="kurashiki" || destination_name=="KURASHIKI")
        {
            destination=17;
            if(destination>size)
            {
                goto pos1;
            }
        }
        else
        {
            cout<<"Enter valid destination."<<endl;
            goto lable1;
        }
        return destination;
}
void mapping::city_names(){
		cout<< "tokyo        : stop 0"<<endl;
        cout<< "sapporo      : stop 1"<<endl;
        cout<< "kyoto        : stop 2"<<endl;
        cout<< "hiroshima    : stop 3"<<endl;
        cout<< "fukuoka      : stop 4"<<endl;
		cout<< "osaka        : stop 5"<<endl;
        cout<< "nagasaki     : stop 6"<<endl;
        cout<< "sendai       : stop 7"<<endl;
        cout<< "matsue       : stop 8"<<endl;
        cout<< "shizuoka     : stop 9"<<endl;
        cout<< "otsu         : stop 10"<<endl;
        cout<< "sagamihara   : stop 11"<<endl;
        cout<< "gifu         : stop 12"<<endl;
        cout<< "matsumoto    : stop 13"<<endl;
        cout<< "sakai        : stop 14"<<endl;
        cout<< "kofu         : stop 15"<<endl;
        cout<< "yamagata     : stop 16"<<endl;
        cout<< "kurashiki    : stop 17"<<endl;
}
void mapping::take_city(){
	int s=citysource();
	int d=citydestination();
	dijkstra(city, s, d);
}
string mapping::getdestination(){
	return destination_name;
}
string mapping::getsource(){
	return source_name;
}
