//HSQTAN3.C

inherit ROOM;

void create()
{
	set("short", "��̶");
	set("long", @LONG
�������ٲ��µĺ�̶��ˮ���İ��ޱȣ������ƺ��м������ڣ�
��ʵ�ڿ�������ͨ��δ���ˮ�б���̹ǣ������������ܣ���ֻ��
��������һ��һ����ʧ��
LONG );
	set("exits", ([
		"east" : __DIR__"hsqtan3",
		"west" : __DIR__"hsqtan2",
		"south" :__DIR__"hsqtan4",
		"north" :__DIR__"hsqtan3",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	object me;
        int meqi,meneili,decqi,mq;
	me=this_player();
	meqi=(int)me->query("qi");
        meneili=(int)me->query("neili");
        mq=(int)me->query("max_qi");
        decqi=(int)(mq/(random(4)+5+meneili/200));
	meqi=meqi-decqi;
	me->set("neili",0);
        if(meqi>0) me->set("qi",meqi);
        else me->die();
}

