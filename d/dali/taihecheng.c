//Room: /d/dali/taihecheng.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","̫�ͳ�");
	set("long",@LONG
�˳�����������θ���ȫ����İ����ʯ�ݳɣ������࣬��������
���ϡ�̫�Ͳ����ǣ����˿�Ϊ�������٣������Ϻ;������Ǵ����
�ı��Ż������������������ڴ˼ӹ̳ǳأ���פ������������һЩ��
�Ĳ���۾ӡ�������һƬƽԭ����ʮ���������ǡ�
LONG);
	set("outdoors", "dali");
	set("objects",([
	    __DIR__"npc/bing": 2,
	    __DIR__"npc/jiang": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"dehuabei",
	    "south"  : __DIR__"dalinorth",
	]));
	setup();
	replace_program(ROOM);
}

