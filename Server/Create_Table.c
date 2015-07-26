#ifndef HEADER_H_METHOD
#define HEADER_H_METHOD
#include"Header.h"
#include"Method.h"
#include <my_global.h>

#endif

void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);        
}

void Create_Table(void);
void Create_Table(void)
{
	struct login admin;
	FILE *pFilePointer=NULL;
	MYSQL *con = mysql_init(NULL); 
 	if(con==NULL) 
 	 {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
	  }  
  if (mysql_real_connect(con, "localhost", "root", "labh","rll", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  if (mysql_query(con, "DROP TABLE IF EXISTS Cars")) 
  {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "create table IF NOT EXISTS Flat_Account(FlatNo int,FlatOwner varchar(25),ContactNo varchar(11),ResidingFrom varchar(15),NoofMembers int, PRIMARY KEY (FlatNo))"))
   
  {      
      finish_with_error(con);
	}
  if (mysql_query(con, "create table IF NOT EXISTS Login_Credentials(FlatNo int,FlatOwner varchar(25),LoginName varchar(10),LoginPwd varchar(15),AltUser1LoginName varchar(10),AltUser1LoginPwd varchar(15),AltUser2LoginName varchar(10),AltUser2LoginPwd varchar(15), FOREIGN KEY (FlatNo) REFERENCES Flat_Account(FlatNo))"))
   
  {      
      finish_with_error(con);
	}
  if (mysql_query(con, "create table IF NOT EXISTS Registered_Appliances(FlatNo int,FlatOwner varchar(25),Appliance1 varchar(25),Appliance2 varchar(25),Appliance3 varchar(25),Appliance4 varchar(25),Appliance5 varchar(25),Appliance6 varchar(25),Appliance7 varchar(25), FOREIGN KEY (FlatNo) REFERENCES Flat_Account(FlatNo))"))
   
  {      
      finish_with_error(con);
	}
  if (mysql_query(con, "create table IF NOT EXISTS Appliance_Status(FlatNo int,Appliance1State bool,Appliance2State bool,Appliance3State bool,Appliance4State bool,Appliance5State bool,Appliance6State bool,Appliance7State bool, FOREIGN KEY (FlatNo) REFERENCES Flat_Account(FlatNo))"))
   
  {      
      finish_with_error(con);
	}
	mysql_close(con);

	strncpy(admin.strUserName,"A123",10);
	strncpy(admin.strUserPassword,"1234",15);
	pFilePointer=fopen("Admin.txt","wb");
	fwrite(&admin,sizeof(struct login),bOne,pFilePointer);
	fclose(pFilePointer);
}

 /*int main()
 {
 	Create_Table();
 }*/
