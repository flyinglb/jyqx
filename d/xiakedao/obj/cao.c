// cao.c
inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name("���Ĳ�", ({"fuxin cao","cao"}));
        set("unit", "��");
        set("long", "����һ���޸�С��,���ú�С,ȴ����һ���������ٵĸо���\n");
        setup();
}
int do_eat(string arg)
{
//        int force_limit, neili_limit;
        if (!id(arg))  return notify_fail("��Ҫ��ʲ��\n");
        if(arg=="cao")
        {
               message_vision(HIG "���Ը��Ĳ�? �������ٺȰ�...\n" NOR, this_player());
//               force_limit = this_player()->query_skill("force",1)*10;
//               neili_limit = this_player()->query("max_neili");
//               if ( neili_limit <= force_limit  )
//               {
//                      this_player()->add("max_neili",5);
//                      this_player()->unconcious();
//               }
//               message_vision(HIG "$N����һ�긯�Ĳݣ���Ȼ���е������...\n" NOR, this_player());
//               destruct(this_object());
        }
        return 1;
}
