//Room: /d/dali/jingzhuang5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����");
	set("long",@LONG
��״���������Ľǹ��л�ͭ�����ա���ֻ���գ��ڽ�����һö
��ͷ�п׵�ͭ�ܣ������н�����Ƭ���տڡ��վ����ո����ǿ��ġ�ÿ
�����紵������������ͭ�ܣ����ո��ڿ�����������㷢���ö���
���С�����ƽ�����յ��������գ��������ܹ��ɽ��ǵľ�տ���ա�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "up"    : __DIR__"jingzhuang6",
	    "down"  : __DIR__"jingzhuang4",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

