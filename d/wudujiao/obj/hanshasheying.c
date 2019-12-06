// hanshasheying.c ��ɳ��Ӱ

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
        set_name("��ɳ��Ӱ", ({ "han sha she ying", "hssy" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�����嶾�̵����Ű�������ɳ��Ӱ����������һ�������������������䡣\n���м���һ������С���У�һҪ������һ��(shot)�Ϳ��Է����ϸ��ţë�Ķ��롣\n") ;
                set("unit", "��");
                set("value", 0);
                set("zhen", 10);
                set("material", "iron");
                set("armor_prop/armor", 3);
        }
        setup();
}

void init()
{
        add_action("do_shot","shot");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;
//        string fam;

        me = this_player();

        if( me->query_temp("armor/waist") != this_object() )
                return notify_fail("������������һ������⣡�㻹û�Ѻ�ɳ��Ӱװ���أ�\n");

        if( !arg ) return notify_fail("�����˭���京ɳ��Ӱ��\n");

        if( !objectp(target = present(arg, environment(me))) )
                return notify_fail("����û������ˡ�\n");

//      if( !target || !target->is_character() || !me->is_fighting(target) )
//              return notify_fail("��ɳ��Ӱֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if(me->is_busy() )
                return notify_fail("����æ���ġ�\n");

        if( this_object()->query("zhen") < 1 ) {
                remove_call_out("destroy_box");
                call_out ("destroy_box" , 0 ) ;
                return notify_fail("�����еĶ����Ѿ�����ˡ�\n");
                }

        if( !objectp(ob = present("han sha she ying", me)) )
                return notify_fail("��û�����ֶ�����\n");

        myskill =  me->query_skill("duji",1) + me->query_skill("dodge",1);
        tgskill =  target->query_skill("dodge",1);
        mylev =  me->query_skill("duji");

        if( (string)this_player()->query("family/family_name")!="�嶾��" ) {
                message_vision("\n$N����������һ���Ұ���\n", me);
                return 1;
                }
        if( ob->query("own_name")!= me->query("id") ) {
                message_vision("\n$N����������һ���Ұ���\n", me);
                remove_call_out("destroy_box");
                call_out ("destroy_box" , 0 ) ;
                return 1;
                }

        if ( mylev <= 50 )
                return notify_fail("��Ķ��������������޷�ʹ�ú�ɳ��Ӱ��\n");

        this_object()->add("zhen", -1);
        message_vision(HIR"\n$Nһ����Ц�����ֲ������������һ����ֻ����һ�����͵��ƿ�����\n"NOR,me,target);
        me->start_busy(2+random(2)) ;
        if( !target->is_killing(me) ) target->kill_ob(me);
        if(  random(myskill) < tgskill )
                message_vision("\n$n���һ�����͵�һ�����ذδ����г����������ߣ����������$N�Ķ��룡\n",me,target);
        else {
                message_vision("\n$n����������������ϸ��ţë�Ķ������һ�����ɵķ���һ���Һ���\n",me,target);
                tell_object (target, HIR "\n��ֻ�������ϡ���ǰһʹ�������������Ѱ���һ�����ж��ˡ�\n"NOR);
                damage=(int)me->query_skill("duji",1)*4 - (target->query("max_neili")/5);
                if( damage < 100 ) damage = 100;
                if( damage > 800 ) damage = 800;
                target->receive_wound ("qi",damage) ; 
                target->apply_condition("snake_poison", (int)target->query_condition("snake_poison") + damage/5 );
                target->apply_condition("wugong_poison", (int)target->query_condition("wugong_poison") + damage/5 );
                target->apply_condition("zhizhu_poison", (int)target->query_condition("zhizhu_poison") + damage/5 );
                target->apply_condition("xiezi_poison", (int)target->query_condition("xiezi_poison") + damage/5 );
                target->apply_condition("chanchu_poison", (int)target->query_condition("chanchu_poison")+damage/5 );
                target->start_busy (4);
                }
        return 1;
}

void destroy_box()
{
        message_vision("��Ȼ" + (string)this_object()->query("name") + "���ڵ��ϣ�ˤ����һ����Ƭ��\n", environment(this_object()));
        destruct(this_object());
}
