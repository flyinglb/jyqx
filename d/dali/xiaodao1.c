//Room: /d/dali/xiaodao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����С��");
	set("long",@LONG
������С������ǰ��Լ��ʮ���ߣ�ֻ������������Ũ����죬һ����
ȪǶ����䣬������ʯ��Ȫˮ��������������Ǯ���ڳ��У����仺�����䣬
���������ɸ�£��ص�������˸������Ȫˮ�������ر߾����Լ�����ߵ�
�ط���һ�ֿɺϱ������ɣ����Ȫ�ϣ����Խ���Сͤ��С��������ʮ����
�ġ� 
LONG);
	set("objects", ([
	   __DIR__"npc/maque": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northup"  : __DIR__"qingxi",
	    "south"    : __DIR__"heilongling",
	    "west"     : __DIR__"hudiequan",
	]));
	setup();
	replace_program(ROOM);
}

