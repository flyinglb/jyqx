// shufang.c
inherit ROOM;

string* books = ({
        "/clone/book/book-bamboo",
//        "/clone/book/book-paper",
        "/clone/book/book-silk",
        "/clone/book/book-stone",
        "/clone/book/book-iron",
});

void create()
{
        set("short", "�鷿");
        set("long", @LONG
�������鷿����ǽ��һ����ܣ������˵������ָ������ɵ��书
�ܽ塣ʯ���м����ʯ���ͼ���ʯ�ʣ����͵���ľ����������������
���顣
LONG );
        set("exits", ([
                "west" : __DIR__"dating"
        ]));
        set("objects", ([
                books[random(sizeof(books))] : 1,
        ]));
        setup();
        replace_program(ROOM);
}
