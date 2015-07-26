CFLAGS=-I/usr/include/mysql -DBIG_JOINS=1  -fno-strict-aliasing  -g
CLINK=-L/usr/lib/i386-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -ldl

SOURCES=serv.o serverMenu.o Server_Admin_Login.o Server_FamilyMember_Login.o Server_FlatOwner_Login.o Create_Table.o Server_Admin_Menu.o Server_Create_FlatAccount.o Server_Delete_Account.o Server_View_ApplianceStatus.o Server_Generate_Report.o Send_Message.o Receive_Message.o Server_FlatOwner_Menu.o Server_Registered_Appliance.o Server_Modify_ApplianceControl.o Server_Control_Appliance.o Server_Change_LoginCredentials.o Server_Add_FamilyMembers.o

server: ${SOURCES}
	cc -o server  ${SOURCES} ${CFLAGS} ${CLINK}
clean:
	rm server *.o
