:create service
sc create MyRestSQL binPath= "C:/myrestsql/myrestsql.exe" type= own start= auto DisplayName= "MyRestSQL"

sc start MyRestSQL
