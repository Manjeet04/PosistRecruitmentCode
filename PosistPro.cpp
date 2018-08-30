// Code for Posist Online Recruitment
// Genesis.
#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int AUTO = 0;

struct Genesis
{
    string timestamp;
    string data;
    int nodeNumber;
    string nodeId;
    struct Genesis *referenceNodeId;
    vector<struct Genesis*> childReferenceNodeId;
    struct Genesis *genesisReferenceNodeId;
    string HashValue;



} ;
string getCurrtime()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
  string str(buffer);

  return str;
}


string generateNodeId()
{

    string nodeid = "";
    for(int j=0;j<10;j++)
    {
        int num = rand()%10;
        char numb = num+48;
        nodeid = nodeid + numb;

    }
    return nodeid;


}

string getEncryptedData(int OwnerId, float value, string OwnerName)
{
    // Encryption algo : Convert each ASCII code A to Z, B to Y.. using this pattern.
    // for numeric pattern, 0:9, 1:8, 2:7, 3:6, 4:5... and so on.
    // special characters have no change to them.
    // underscore is used as seperator for hashes.
    // string = id+value+name
    // value of float changed to int

    string Encrypted = "";
    string idstring = "";
    cout<<"hello"<<" ";
    while(OwnerId!=0)
    {

      int newnum = OwnerId%10;
      newnum = 9-newnum;
      char numb = newnum + 48;

      idstring.push_back(numb);
      OwnerId = OwnerId/10;

    }
    reverse(idstring.begin(),idstring.end());
    Encrypted = Encrypted + idstring;

    int newval = value;
    cout<<"hi"<<" ";
    idstring = "";
    while(newval!=0)
    {

int       newnum = newval%10;
      newnum = (9-newnum);
      char numb = newnum + 48;

    idstring.push_back(numb);
      newval = newval/10;

    }
    reverse(idstring.begin(),idstring.end());
    Encrypted = Encrypted + idstring;
    cout<<"yo";
    for(int i=0;i<OwnerName.size();i++)
    {
        if(islower(OwnerName[i]))
        OwnerName[i] = ('z' - OwnerName[i])+97;
        else if(isupper(OwnerName[i]))
        {
            OwnerName[i] = ('Z' - OwnerName[i])+65;

        }



    }
    //cout<<"dusfdk"<<" ";
    Encrypted = Encrypted + OwnerName;
    return Encrypted;




}

string getDecryptedData(string OwnerName,int OwnerId,float value)
{
    // Decryption algo : Convert each ASCII code A to Z, B to Y.. using this pattern.
    // for numeric pattern, 0:9, 1:8, 2:7, 3:6, 4:5... and so on.
    // special characters have no change to them.
    // underscore is used as seperator for hashes.
    // string = id+value+name
    // value of float changed to int

    string Decrypted = "";
    string idstring = "";
    cout<<"hello"<<" ";
    while(OwnerId!=0)
    {

      int newnum = OwnerId%10;
      newnum = 9-newnum;
      char numb = newnum + 48;

      idstring.push_back(numb);
      OwnerId = OwnerId/10;

    }
    reverse(idstring.begin(),idstring.end());
    Decrypted = Decrypted + idstring;

    int newval = value;
    cout<<"hi"<<" ";
    idstring = "";
    while(newval!=0)
    {

int       newnum = newval%10;
      newnum = (9-newnum);
      char numb = newnum + 48;

    idstring.push_back(numb);
      newval = newval/10;

    }
    reverse(idstring.begin(),idstring.end());
    Decrypted = Decrypted + idstring;
    cout<<"yo";
    for(int i=0;i<OwnerName.size();i++)
    {
        if(islower(OwnerName[i]))
        OwnerName[i] = ('z' - OwnerName[i])+97;
        else if(isupper(OwnerName[i]))
        {
            OwnerName[i] = ('Z' - OwnerName[i])+65;

        }



    }
    //cout<<"dusfdk"<<" ";
    Decrypted = Decrypted + OwnerName;
    return Decrypted;


}


struct Genesis *createNode(string OwnerName, int OwnerId, float value, int nodeNo, string nodeid, struct Genesis *parent, bool isGen, string time)
{
    string FinalData = getEncryptedData(OwnerId,value,OwnerName);
 //cout<<FinalData<<" ";
    struct Genesis *node = (struct Genesis*)malloc(sizeof(struct Genesis));
   // cout<<"fdf"<<" ";
    node->data = FinalData;
    node->timestamp = time;
    //cout<<"dsidd"<<" ";
   // cout<<nodeNo<<endl;
   // cout<<nodeid;
    node->nodeNumber = nodeNo;
    node->nodeId = nodeid;
   // cout<<" tre";
    if(isGen)
    {node->referenceNodeId = 0;
    node->genesisReferenceNodeId = node;

    // HashValue is calculated as first and last character of dataString, time, nodeid

    node->HashValue = FinalData[0] + FinalData[FinalData.size()-1] + time[0]+time[time.size()-1] + nodeid[0] + nodeid[nodeid.size()-1];
    cout<<node->data<<" "<<node->timestamp<<" "<<node->nodeNumber<<" "<<node->nodeId<<" "<<node->HashValue<<" ";
    return node;
    }





};

int main()
{
        struct Genesis *root = (struct Genesis*)malloc(sizeof(struct Genesis));

    while(1)
    {
    cout<<"WELCOME TO GENESIS WORLD\n";
   char d;
   cout<<"Enter What You Wish to do\n1.Create Genesis Node\n2.Exit(Enter the option)";
   int opt;
   cin>>opt;
   switch(opt)
   {
       case 1 : {
           string ownername,nodeId;
        int ownerid;
        float data;
       cout<<"Enter the Owner Name: ";
       getline(cin>>ws,ownername);
       //cout<<"\n";
       cout<<"Enter the OwnerId: ";
       cin>>ownerid;
       cout<<"Enter the data: ";
       cin>>data;
       root = createNode(ownername, ownerid, data, ++AUTO, generateNodeId(), 0,1, getCurrtime() );
       cout<<"Genesis Made";
       break;
       }
       case 2 : exit(0);


   }
    }}

