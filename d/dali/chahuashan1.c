//Room: /d/dali/chahuashan1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨ɽ");
	set("long",@LONG
��վ��һ��Сɽ������£�����ʢ���軨����Ʒ�ֵĲ軨��
���������������ƬСɽ��Ҳ�����˺ò衣���߲�Զ���Ǵ����
�ı����ˡ�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"northgate",
	    "eastup"    : __DIR__"chahuashan2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

