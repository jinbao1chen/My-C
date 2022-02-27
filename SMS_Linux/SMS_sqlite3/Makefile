TARGET:=./destdir/SMS_sqlite3
OBJS:=StudentManagementSystem_sqlite3.o
LIBS:=-lsqlite3

$(TARGET):$(OBJS)
	$(CC) $^ -o $@ $(LIBS)

clean:
	$(RM) $(TARGET) $(OBJS)
.PHONY:clean
