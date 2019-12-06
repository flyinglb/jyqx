//LUCAS 2000-6-18
// Room: book.c

inherit ROOM; 
string* books = ({
        __DIR__"obj/book-bamboo",
        __DIR__"obj/book-silk",
        __DIR__"obj/book-stone",
        __DIR__"obj/book-iron",
});
void create()
{
        set("short","�鷿");
        set("long",@LONG
�����ǰ����ڵ��鷿��һ��֮�ڣ������˸����鼮��������
��Ȼ�����Դ󣬵�˵��ѧ�ʣ�ȴ����Ҳ�Ǳ���ʫ�飬ѧ���峵��
�������ܣ����СС������ʮ�����ɡ������ڵ���ͯ������Ϊ
������
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"weideju",   
            "south"  : __DIR__"bridge",
        ]));
        set("objects", ([  
                __DIR__"npc/su" : 1,  
                __DIR__"obj/feixue-book" : 1,  
                books[random(sizeof(books))] : 1,
                books[random(sizeof(books))] : 1,
        ]));
        setup(); 
        replace_program(ROOM);
}

