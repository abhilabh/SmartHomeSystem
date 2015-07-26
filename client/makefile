SOURCES=clnt.o clientMenu.o Admin_Login.o FlatOwner_Login.o FamilyMember_Login.o Admin_Menu.o Create_FlatAccount.o Delete_Account.o View_ApplianceStatus.o Generate_Report.o Send_Message.o Receive_Message.o FlatOwner_Menu.o Register_Appliance.o Modify_ApplianceControl.o Control_Appliance.o Change_LoginCredentials.o Add_FamilyMembers.o
client: ${SOURCES}
	cc  -o client ${SOURCES}

clean:
	rm client *.o
