// room: /d/xingxiu/btshan
// Jay 3/27/96

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
���Ǵ�˵�����صİ���ɽ��ԶԶ��ȥ��������ɳ�ѻ��γɵ�ɽ�����
һֻ���յļ�����һ��ɽ�����������ǰ��ɽ�ź�һ��С·ͨ��һ��ɽ��
�ϵ�ɽׯ�������ǡ�������ŷ�������լ��һ���˴���ȥ�������ˡ�
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"shamo4",
            "westup" : __DIR__"btshan1",
        ]));
        set("objects", ([ 
            __DIR__"npc/ke" : 1,
            __DIR__"npc/snake" : 3,
        ]) );

//        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
   if (dir =="westup" ) {
        if (objectp(present("snake", environment(me))))
                return notify_fail("���󲻹��������ɽ?\n");

        if (objectp(present("ouyang ke", environment(me))))
                return notify_fail(
"ŷ���˶������ȣ�һ���ֵ�ס�����ȥ·���常���������������������\n");
        
       
        message("vision", me->name() +"��������ȥ��\n",environment(me), ({me}) );
        me->move(__DIR__"btshan1");
        write(HIY "ŷ���湭���ȭ�����ڷ������������Ľ�����˫ĿԲ����\n" NOR);
        write(HIY "��Ȼ��ŷ����˫��һ�ţ�����ƽ�����������\n" NOR);
        write(HIY "��һ���������ǰ�أ���о�������������������һ����\n" NOR);
        write(HIY "��ƽ�ɳ��˰���ɽׯ��\n" NOR);
        me->move(__DIR__"btshan");
        message("vision", "��ɽ�Ϸ���һ����������ϸһ����ԭ����" + me->name() +"��\n"
,environment(me), ({me}) );
        me->set("qi",10);
        me->unconcious();
        return notify_fail("");
   }
   return ::valid_leave(me, dir);
}

