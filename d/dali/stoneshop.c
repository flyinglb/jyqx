//Room: /d/dali/stoneshop.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ʯ��");
	set("long",@LONG
����ض���һɽʯ������Ȼ�Ļ��ƶ��������£��Ǳ��Ǵ�������
�Ĵ���ʯ���ô���ʯ�е�ˮī��ʯ�����Ļ�����������̶ȣ�ʹ��̾
����ֹ������ʱ���������̽��嶼���Դ���ʯ���ҾӰ��衣ʯ����
��ͷ�üã��ô���ĥ֮�������ڶ���һ��������ͷ���Ű��ӣ�������
��С����ָ�����»�ơ�
LONG);
	set("objects", ([
	   __DIR__"npc/shijiang": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"taiheeast",
	]));
	setup();
	replace_program(ROOM);
}

