//ROOM: /d/yanziwu/biheqiao.c

inherit ROOM;

void create()
{
        set("short", "�̺���");
        set("long",@LONG
�������ѵĺ�Ҷ���棬һ���������۵�С��ͨ��ˮ�е�һƬС�ޣ�
���ϻ������̣��ƺ����ж��졣
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
            "west" : __DIR__"huayuan",
            "east" : __DIR__"tingxiang",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
