//RJQTING.C

inherit ROOM;

void create()
{
	set("short", "��ľ�����");
	set("long", @LONG
���Ǿ�ľ��Ĵ�������Ȼ��������֮�ˣ�����ȴ���õù�
ɫ���㡣���������ͽ�����ľ֮�У���ľ��ӳ����Ϊ���ܡ���
Ȼδ�⼷�ȣ�ȴ������������׹������������г�������͹�
ľ���㣬ʮ�ֶ��ˡ�����ʹ������ɫ�����ض����Ȳ裬ȫ����
����˵ĵ�������ľ����������׼���˼���ľ�ľ׮��ר����
�С�
LONG);
	set("exits", ([
		"down" : __DIR__"jmqshenmu",
	]));
        set("objects",([
                __DIR__"npc/wensong":1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
