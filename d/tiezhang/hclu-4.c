// Room: /u/zqb/tiezhang/hclu.c

inherit ROOM;


void create()
{
	set("short", "�Ĳ�·");
	set("long", @LONG
    ����һ�����ߵ�С·�ϣ����ԻĲ���ϥ��������أ��ƺ������� 
����ɽʯ������������գ�����ȫ�ޣ�����������һƬ����֮�У�ʹ���￴
�������������ľ���
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"wmfeng",
 "southdown" : __DIR__"hclu-3",
]));
	set("no_clean_up", 0);
    set("outdoors", "tiezhang");
	setup();
}
int valid_leave(object me, string dir)
{
 if ((dir != "northup") && (dir != "southdown"));
 if (dir == "northup"){
            me->receive_damage("qi", 50);       
            write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
    }

 if (dir == "southdown"){
        me->receive_damage("qi", 50);       
        write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
}
return 1;
}

