//room: /d/mingjiao/neishi.c
inherit ROOM;

void init();
void create()
{
        set("short","��������");
        set("long", @LONG
�������������ҡ�СС��ǰ�Ĵ��⣬����ȥ�����������ΡΡ��
�ء��������Ⱦ����Ƶ�������ۼ�������쳣��ǰ����һ������Ů����
��էһ������������ò����������г�������
LONG );
        set("exits",([
            "out" : __DIR__"dadian",
        ]));
        set("no_fight","1");
        set("no_beg","1");
        set("objects",([
            CLASS_D("mingjiao")+"/xiaozhao":1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
