// guandao1.c �ٵ�
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
����һ�����������ͨ���书�򡣵��ϵ����˺ܶ࣬����ǵ�
��ͷ�Լ����Լ���·����Ȼ������������õõ�����������һ��
������ƥ���������߷ɳ۶�����������һƬ��ɳ��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "west" : __DIR__"guandao2",
                "east" : "/d/city4/road3",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
