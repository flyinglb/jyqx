// shandong.c
// Java Oct.10 1998

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����Сɽ�������һ��ǿ���ˮ���Ե����������γ�һ��С��
�����⡣������ٽ�һ������Ļ����͵�Ҫ����ˮ���ˡ�����ɵ�
С�ӱߡ������ҪǱˮ�ˡ�
LONG
        );
        set("outdoors", "gumu");
        set("item_desc", ([
                "dong" : "һ�����䡢�İ����ֲ���Сɽ����\n",
        ]));
        set("exits", ([
                "out"      : __DIR__"xiaohebian",
                "westdown" : __DIR__"mishi7",
        ]));

        setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "westdown" && me->query("family/family_name")!="��Ĺ��")
	{
		return notify_fail("��ô����ˮ����������ȥ��ɱѽ��\n");
	}
	if (dir == "westdown" && me->query("family/family_name")=="��Ĺ��")
	{
message_vision(HIG"$N����һԾ������ˮ̯֮�У���������������ι���������һ�̣�\n"NOR,me);
message_vision(HIG"ȴץ�˿ա�ͻȻ$N��ǰһ����һ�ɰ��������������$N����һ�����ڡ�\n"NOR, me);
		return 1;
	}
        return ::valid_leave(me, dir);
}
