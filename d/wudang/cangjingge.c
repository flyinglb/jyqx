// cangjingge.c �ؾ���
// by Xiang
// 05/30/96 Marz

inherit ROOM;

string* books = ({
        "laozi1",
        "daodejing-i",
        "laozi2",
        "daodejing-i",
        "laozi8",
        "daodejing-i",
        "laozi13",
        "laozi1",
        "laozi16",
        "daodejing-i",
        "laozi18"
});

void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
�����ǲؾ��󣬿�ǽ��һ����ܣ������˵��̵ĵ伮��������һ������
�εĴ����ӣ�����Ҳ�������顣һ����ͯ���������鼮��
LONG );
        set("exits", ([
                "southdown" : __DIR__"xilang",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/daotong" : 1,
                "clone/book/"+books[random(sizeof(books))] : 1,
                "clone/book/"+books[random(sizeof(books))] : 1
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
