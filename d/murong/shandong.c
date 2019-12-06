// /u/beyond/mr/shandong.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",BLU"Сɽ��"NOR);
        set("long",@long
�����Ǽ�ɽ��ĵ������ҡ�������С��ȴҲ�����ȫ��ʯ��ʯ�Σ�ʯ��
ʯ���������ڷŵļ�������Ҳ����ʯ�Ƶġ������ƺ��ܾ���ǰ����������
ס����ǽ��(wall)�Ϻ������Щʲô��
long);
        set("item_desc", ([

 "wall" : "����һ����ǽ�棬�������Щ��ֵ�ͼ�Ρ�\n",
        ]));

        setup();
}

void init()
{
        add_action("do_break","break");
        add_action("do_study", "study");
        add_action("do_study", "du");
}


int do_study(string arg)
{
	object me;

	me = this_player();
        if ( arg != "wall" )
                 return 0;
	if (me->is_busy() || me->is_fighting()) {
		write("����æ���ģ�\n");
		return 1;
	}
	if ( (int)me->query_skill("literate", 1) < 1) {
		write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}
        if ( (int)me->query("jing")<30) {
                 me->receive_damage("jing", 10);
                 write("��̫���ˣ��Ѿ�û���������ж�ǽ���ϡ��Ź�ͼ�Ρ����ˣ�\n");              
	        return 1;
	}
    me->receive_damage("jing", 30 + random(15));

	tell_room(this_object(), me->name() + "��ר���о�ǽ���ϵġ��Ź�ͼ�Ρ���\n", ({ me }));

    if ( (int)me->query_skill("blade", 1) < 101 && (int)me->query_skill("blade", 1) >= 40)
	{
        me->improve_skill("blade", me->query("int"));
        write("�����ǽ���ϵġ��Ź�ͼ�Ρ���ĥ��һ�ض����ƺ��Ի������������ĵá�\n");
		return 1;
	}
        if ( (int)me->query_skill("blade", 1) < 40) {
write("�㿴�˰��컹�ǿ����������ͼ����ʲô���塣\n");
return 1;
}

	write("����ŹŹ�ͼ���о���һ�ᣬ�������Ѿ��о�͸����������˵�Ѻ��������ˡ�\n");

	return 1;
}


 int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="wall" ) {
                write("��Ҫ����ʲô�Ķ�����\n");
                return 1;
        }

  message_vision(
   "$N����һ������˫��ͬʱ�ĳ���\n", this_player());

  if (n>=200) {
        message_vision(
 "$Nֻ��һ�����䡱��һ����$N����ʯ���ˣ�һ�����ϵĶ��ڳ���������ǰ��\n", this_player());
        set("exits/up", __DIR__"jiashan");
        this_player()->set("neili",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N���һ���������������ʲôҲû����������$N����������ǿ��\n", this_player());
        this_player()->set("neili",0);
           }

        return 1;
    }

     void close(object room)
    {
message("vision","��ʯ������ԭλ���ֵ�ס�˶��ڡ�\n", room);
         room->delete("exits/up");
   }


