//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
�����������ɵ���˽����͵͵���ٳ�����������Ϸ�ķ��䣬��Ϊ�����˺�
�ٹ�˵����ǵľ��������Ե�����Ҳ���ֵ���ң����������Ҳûʲô�������
�������������ݽǴ����˼��������ӣ����洫�����е�������Ӧ����������
���棬������������ƽʱ������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"xiaoyuan2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
