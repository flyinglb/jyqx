// midao6.c ʯ��

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
        set("short", "ʯ��");
        set("long", @LONG
����һ��ʯ�������Ϻ�ʯ�����ǻҳ������ó��þ�û��������
�����ʯ����һ����ܣ�����Ҳ���ǻҳ�������һЩ�ƾɵ��鼮��
ǽ����һ��ʯ������Ȼ���࣬ȴҲ����Ϣ��
LONG );
        set("exits", ([
                "west" : __DIR__"midao7",
        ]));
        set("sleep_room", 1);
        set("objects", ([
                books[random(sizeof(books))] : 1,
                books[random(sizeof(books))] : 1,
        ]));
        setup();
        replace_program(ROOM);
}
