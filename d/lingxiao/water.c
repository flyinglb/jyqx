#include <ansi.h>

inherit ROOM;
int do_dive(string arg);

void create()
{
   set("short", "ѩɽ��Ȫ");
   set("long", @LONG
����������ɽ�����֮�䣬��һ����Ȫ����˻˻��ˮ������
��ˮ�����紵ɢ�����¹����γ�һ���Ű�ɫ�Ļ���������ѩɽ֮
�ϣ���Ȼ���д˵��������֮�����಻�����˸�̾����֮���档
�̲���ˮ�У�Ʈ���Ŷ��ѩ�����꣬ƬƬѩ��ƮȻ���£���ˮ��
�����磬�㼴�׷׻�Ϊ�����ɢ���������������Ĵ�ѩɽ֮�ϣ�
Ω����������������컨����ݡ�һ����Ů����Ȫ�������仨��
�����������¡�
LONG
NOR  );
    set("resource/water", 1);
    set("objects", ([
           __DIR__"npc/a-xiu" : 1,
    ]) ); 
        set("resource/water", 1);
        set("exits", ([ 
     "east" :__DIR__"sroad6",
]));

        setup(); 
} 
void init()
{       
        add_action("do_dive","dive");
}

int do_dive(string arg)
{
        object me = this_player();

        if ((arg !="lake" || !arg))
                return notify_fail("��ҪǱʲô��\n");
        if ((int)me->query_skill("force") < 100 ) { 
   message_vision("$N����ˮ����,�ͷ���������Ǳ,ˮѹ����,����һ��,\n������Ҳ���ܲ�ס,�͵ش���������\n",me);
                } 
        else 
        {
message_vision("$N��������,����Ǳȥ,ֻ��ѹ��Խ��Խ��,$Nǿ������,����֧��,����Ǳȥ,\nֻ��ˮ�л���һ��,��ƽ�������ˡ�\n", this_player()); 
                me->move(__DIR__"wave1"); 
        } 
        return 1;
}

