//RJQYUAN.C

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���߽��������Ĵ�Ժ��ȴ����������Ӱϡ�裬��������
�����˵Ĵ�������ȴ�����������̣��������ƺ��Ǵ���Զ�ĵ�
�´����ġ������ߣ���Ҫ������¥�ˡ�Ժ�����׿��������䳡��
��Լ����������������һ��������������������᳡����
LONG );
	set("exits", ([
		"west" : __DIR__"rjqmenlou1",
		"north" : __DIR__"rjqdating",
		"south" : __DIR__"rjqlwch",
        "out": __DIR__"rjqmen",
	]));
/*
        set("objects",([
            CLASS_D("mingjiao")+"/lengqian":1,
            CLASS_D("mingjiao")+"/shuobude":1,
            CLASS_D("mingjiao")+"/zhangzhong":1,
            CLASS_D("mingjiao")+"/pengyingyu":1,
            CLASS_D("mingjiao")+"/zhoudian":1,
            CLASS_D("mingjiao")+"/yinyewang":1,
        ]));
*/
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
