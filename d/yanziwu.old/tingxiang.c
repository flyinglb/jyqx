//ROOM: /d/yanziwu/tingxiang.c

inherit ROOM;

void create()
{
        set("short", "����ˮ�");
        set("long",@LONG
�����ӻ������а˾ż�é��������������ӳ���������£������Ľ
�ݹ��ӵ��Ů�����ס���ˡ�
LONG );
        set("exits", ([
            "west" : __DIR__"biheqiao",
//            "south" : __DIR__"shuiyun",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
