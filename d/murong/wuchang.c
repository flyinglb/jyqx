// /u/beyond/mr/wuchang.c
// this is made by beyond

#include <ansi.h>
#include <room.h>

inherit ROOM;

int do_strike(string arg);

void create()
{
         set("short",HIW"���䳡"NOR);
         set ("long",@long
���������䳡��Ľ�ݼҵĵ��ӡ��Ҷ���������ϰ�书�������䳡��һ�ǣ�
��һ��ר�����������ľ׮(zhuang)�������Ӷ�Χ������������
long);
        set("exits",([
                "west" : __DIR__"yanziwu",
        ]));
        set("item_desc", ([
                "zhuang" : "����һ��ľ׮���ܹ��������ֹ������������������һ�������\n",
        ]));
        set("objects",([
                __DIR__"npc/jiading" : 2,
        ]));
        setup();
}

void init()
{
        add_action("do_strike", "strike");            
        add_action("do_strike","hit");
        add_action("do_strike","ji");
        add_action("do_strike","da");
}

int do_strike(string arg)
{
        object me;
        int jinglicost, maxlevel, level;
	
        me = this_player();
	level = me->query_skill("parry", 1);
        if ( !living(this_player()) || arg != "zhuang" )
                return 0;
        if ( (level = me->query_skill("parry", 1)) < 30 )
                return notify_fail("ƾ�����ڵ��мܹ����޷����ľ׮��������\n");
        maxlevel = 201;
        if (me->query("family/family_name")!="����Ľ��")
                maxlevel = 201;
        if (level >= maxlevel)
                return notify_fail("�����ľ׮���صش�������Ǵ��ľ׮�Ѿ��޷�ʹ��Ļ����м�����ˡ�\n");
        jinglicost = level / 4 + random(level / 4);
        if (me->query("jing") <= jinglicost) {
                write("�㾫�������Ѿ�û����������ľ׮�ˣ�\n");
                return 1;
        }
        me->receive_damage("jing", jinglicost);
        write("�����ľ׮���صش�������ö���Ļ����м������ٽ���\n");
        if (!random(5)) tell_room(this_object(),
                me->name() + "�������صػ���ľ׮��\n", ({ me }));
        me->improve_skill("parry", me->query("int"));       
        return 1;
}

