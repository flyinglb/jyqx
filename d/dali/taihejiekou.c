//Room: /d/dali/taihejiekou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","̫�ͽֿ�");
	set("long",@LONG
̫�ͽ�������������ϱ��ţ���������ǳ�����Ҫ�ֵ�������
������ڴ�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ��������������ﲻ
����������߱�ֲ�ɰأ���Ŀ�Դ䡣���ھ������ᷱ�ӣ�ϰ�׸��죬
��ʳ�����޲�������ԭ��̫ѧ���ǵ�����֮��͸�ҿ��š����������
�йٵ�ͨ��ԭ��
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"   : __DIR__"paifang",
	    "south"   : __DIR__"center",
	    "east"    : __DIR__"taiheeast",
	    "west"    : __DIR__"sheguta",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

