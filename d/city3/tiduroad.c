// Room: tiduroad1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�ᶽ��");
	set("long", @LONG
�ᶽ�־�����Ϊͨ���ᶽ������������һ���������˺��٣�����
��ľ͸��Ǿ����ˡ��ᶽ���˺����������벻���ģ����˺ö������
�����������������ﶼ��������̤�롣
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "south"  : __DIR__"southroad2",
	    "north"  : __DIR__"guangchang",
	]));
	set("objects", ([
	    "/d/city/npc/bing" : 3,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
