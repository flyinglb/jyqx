#include <ansi.h>

inherit F_CLEAN_UP;



int main(object me,string arg)

{

        object ob;

        int jin, qi, zhili, neili, shiwu, yinshui;


         if (wiz_level(me) >= wiz_level("(wizard)") )

        {

                if(arg)

                {

                if (!find_player(arg))

                  return notify_fail(HIR"�����Ҳ�������!\n"NOR);

                  ob = find_player(arg);

                }

                if(!arg) ob=me;

        }

        else

        {

        if(!arg) ob=me;

        if(arg) 

        if(arg!=me->query("id")) 

        return notify_fail(HIR"����Ȩ�ָ����˵�״̬��\n"NOR);

        ob=me;

        }



        jin = ob->query("max_jing");

        qi =ob->query("max_qi");

        zhili = ob->query("max_jingli");

        neili = ob->query("max_neili");

        shiwu = ob->max_food_capacity();

        yinshui = ob->max_water_capacity();

        ob->set("eff_jing", jin);

        ob->set("eff_qi", qi);

        ob->set("jing", jin);

        ob->set("qi", qi);

        ob->set("jingli", zhili);

        ob->set("neili", neili);

        ob->set("food", shiwu);

        ob->set("water", yinshui);

        ob->set("douzhi", ob->query("eff_douzhi"));


        if(ob==me)

        return notify_fail(HIG"���״̬���»ָ���ϣ�\n"NOR);

        tell_room(ob,HIG+me->query("name")+"�����״̬���»ָ���ϣ�\n"NOR);

        return notify_fail(HIC"�㽫"+ob->name()+"��״̬���»ָ���ϣ�\n"NOR);

}







int help(object me)

{

  write(@HELP

ָ���ʽ : full



��ָ�������ָ����еľ�����

HELP

    );

    return 1;

}

