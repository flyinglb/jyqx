 // this is made by beyond
// /u/beyond/mr/shangyuezhai.c
// update 1997.6.20
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIY"����ի"NOR);
         set("long",@long
����ի��ΪĽ�ݼ�ÿ������֮ҹ������ġ����渻���ûʣ��Ϲ�Ӧ�о�
�У��Ա���Ѿ���ź��ţ�ÿ������֮ʱ��һ����С�����������£������µ�
ͬʱ��Ҳ��������˴����ʹ�������������ã������������һ�����ȡ�
long);
         set("exits",([
		"west" : __DIR__"neitang",
		"east" : __DIR__"cl5-2",
		"south" : __DIR__"cl5-5",
	]));
        setup();
}


