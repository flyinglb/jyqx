// xiaocun.c С��ׯ
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "С��ׯ");
        set("long", @LONG
����һƬС��ׯ��������һ��Сɽ�������ľ����Ƕ����ٵ�
����ȥ����Ȼ���书�򲻹����塢�����ɽ·��������Ը�������и�
Ů��֯���ճ����������Ъ���ϴ�ͳ��������Ȼ��ƶ��ȴ������ң��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northwest" : __DIR__"guchang",
                "southdown" : __DIR__"shanlu1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
