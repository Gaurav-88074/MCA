import pymysql
host = "localhost"
user = 'root'
password='root'
database='rough'
port = 3306
database = pymysql.connect(
    host=host,
    user=user,
    password=password,
    database=database, 
    port=port
)

def menu()->None:
    print("==============================")
    print("Enter 1 to perfom SELECT query")
    print("Enter 2 to perfom INSERT query")
    print("Enter 3 to perfom UPDATE query")
    print("Enter 4 to perfom DELETE query")
    print("Enter 9 to exit")
    print("==============================")
def createQuery(cursor,query)->None:
    cursor.execute(query)
def displayResult(cursor)->None:
    print("--------------------------------")
    print("Displaying Your Table...")
    print("--------------------------------")
    isEmpty = True
    for i,row in enumerate(cursor.fetchall()):
        print(str(i+1)+".",row)
        isEmpty = False
    if isEmpty:
        print("Your Table is Empty!!")
    print("--------------------------------")

def selectQuery(cursor,query)->None:
    cursor.execute(query)
def insertQuery(cursor,query,database)->None:
    try:
        cursor.execute(query)
        database.commit()
    except:
        print("----------------------------------")
        print("Issue : User Id already exists!!")
        print("----------------------------------")
def deleteQuery(cursor,query,database)->None:
    cursor.execute(query)
    database.commit()
def updateQuery(cursor,query,database)->None:
    cursor.execute(query)
    database.commit()
def getUserChoice(cursor,database)->int:
    while True:
        menu()
        choice = input("Please enter Your Choice [1,2,3,4] : ")
        while choice not in ['1','2','3','4']:
            print("------------------")
            print("Invalid choice!! ")
            print("------------------")
            choice = input("Please enter Your Choice [1,2,3,4] :")
        match choice:
            case '1':
                query = "SELECT * FROM USER"
                selectQuery(cursor,query)
                displayResult(cursor)
            case '2':
                userId =   input("Enter user_id   : ")
                userName = input("Enter user_name : ")
                userAge  = input("Enter user_age  : ")
                query = f"INSERT INTO USER VALUES('{userId}','{userName}',{userAge})"
                insertQuery(cursor,query,database)
                query = "SELECT * FROM USER"
                selectQuery(cursor,query)
                displayResult(cursor)
            case '3':
                query = "SELECT * FROM USER"
                selectQuery(cursor,query)
                displayResult(cursor)
                userId = input("Enter id of that user which you want to update : ")
                userName = input("Enter new user_name : ")
                userAge  = input("Enter new user_age  : ")
                query = f"UPDATE USER SET USERNAME = '{userName}',AGE = {userAge} WHERE ID = '{userId}' "
                updateQuery(cursor,query,database)
            case '4':
                query = "SELECT * FROM USER"
                selectQuery(cursor,query)
                displayResult(cursor)
                userId = input("Enter id of that user which you want to delete : ")
                query = f"DELETE FROM USER WHERE ID ='{userId}'"
                deleteQuery(cursor,query,database)
            case '9':

                break
cursor = database.cursor()
getUserChoice(cursor,database)
# cursor.execute("select * from ram")
# print(*cursor.fetchall())