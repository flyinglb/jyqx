//Room: /d/dali/qiandian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ǰ��");
	set("long",@LONG
�����Ǵ�����ʹ���ǰ���ש���߽���ʮ�־��ɣ�����������
������������巺������ڴ˵��˴�����ƫ�����ϵ�С������
�նԵ��������İ��������Էθ���ʮ����ϡ������͵�������԰, ��
���ǻʹ����š�
LONG);
	set("objects",([
	   __DIR__"npc/taijian": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"yuhuayuan",
	    "south"  : __DIR__"gongmen",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

