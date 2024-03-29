// sleep.c
// Dec.11 1997 by Venus
#include <ansi.h>;
#include <command.h>;
void wakeup(object me, object where);
int wakeup2(object me,object slept,object where);
int birth1(object me,object obj);
void birth2(object me, object where);
//void del_sleeped(object me);

int main(object me, string arg)
{
        object obj, old_target;
//        object *living_list;
//        int i, count;
        int i;
        object *inv;
        mapping fam;
        object where = environment(me);
        seteuid(getuid());

        if ( (!(fam = me->query("family")) || fam["family_name"] != "丐帮")
             && !(where->query("sleep_room"))
             || (where->query("no_sleep_room")) )
             return notify_fail("这里不是你能睡的地方！\n");

        if (me->is_busy())
                return notify_fail("你正忙着呢！\n");
        if( me->is_fighting() )
                return notify_fail("战斗中不能睡觉！\n");
        //modify by byp@MX
        //客店处理
        if (where->query("hotel") && !(me->query_temp("rent_paid"))) {
                message_vision("店小二从门外对$N大叫：把这里当避难所啊！先付钱后再来睡！\n",me);
                return 1;
        }
/*
        //如果在客店，超过三个人就不能 sleep
        if(where->query("hotel")) {
                living_list = all_inventory(where);
                for(i=0; i<sizeof(living_list); i++) {
                        if( !objectp(obj = present(living_list[i], where)) ) continue;
                        if( !obj->is_character() ) continue;
                        if( obj->is_corpse() > 0 ) continue;
                        count++; 
                }
                if(count>2) return notify_fail("现在这里人太多，你怎么也睡不着。\n");
        }
*/

//        if ((time()-me->query("last_sleep"))<120)
//                return notify_fail("你刚睡过一觉，先活动活动吧。 \n");
/*
        if (me->query_temp("sleeped"))
            return notify_fail("你刚在三分钟内睡过一觉，多睡对身体有害无益！\n");
        if (me->query("marks/insleeping"))
        {
            me->set("marks/insleeping",0);
            me->set_temp("sleeped",1);
            call_out("del_sleeped", 179, me);
            return notify_fail(
"由于你上次退出前没有在睡觉后满三分钟，只好现在开始补足。\n");
        }
*/

        if((!arg)||arg==(string)me->query("id"))
        {
            if (where->query("sleep_room"))
            {
                write("你往床上一躺，开始睡觉。\n");
                write("不一会儿，你就进入了梦乡。\n");
                me->set_temp("block_msg/all",1);
                 me->set("last_sleep",time());
        me->set("no_get", 1);
        me->set("no_get_from", 1);
        me->set("no_beg", 1);
        me->set("no_beg_from", 1);
        me->set("no_steal", 1);
        me->set("no_steal_from", 1);
                message_vision(
"$N一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n",me);
            }
            else {
                write("你往地下角落一躺，开始睡觉。\n");
                write("不一会儿，你就进入了梦乡。\n");
                me->set_temp("block_msg/all",1);
                 me->set("last_sleep",time());
        me->set("no_get", 1);
       me->set("no_get_from", 1);
        me->set("no_beg", 1);
        me->set("no_beg_from", 1);
        me->set("no_steal", 1);
        me->set("no_steal_from", 1);
                message_vision(
"$N往地下角落屈身一躺，不一会便鼾声大作，做起梦来。\n",me);
            }

            where->add_temp("sleeping_person", 1);

            if (where->query("hotel"))
                me->delete_temp("rent_paid");
                
            me->set_temp("sleeped",1);
            me->set_temp("in_sleeping",1);
            me->disable_player("<睡梦中>");

            call_out("wakeup",random(10)+1, me, where);

            return 1;
        }

        if(!objectp(obj = present(arg, where)))
            return notify_fail("你想跟谁一起睡？\n");
        if( !obj->is_character() )
            return notify_fail("？脑袋出毛病了？\n");
        if( !userp(obj) )
            return notify_fail("人家可不愿理你！\n");
//can't sleep with npc...
        if(me->query("gender")==obj->query("gender"))
            return notify_fail("？对方跟你可是同性呢．．．\n");
        if( !living(obj) )
            return notify_fail(obj->name() + "没法跟你睡了。\n");
        if (!where->query("if_bed"))
            return notify_fail("就在这里？不太好吧。\n");
        if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 50 )
            return notify_fail("你现在是心有余而力不足。\n");

        if( userp(obj) && (object)obj->query_temp("pending/sleep")!=me )
        {
            message_vision(RED "\n$N含情脉脉地对$n说：我．．．\n\n" NOR, me, obj);
            if( objectp(old_target = me->query_temp("pending/sleep")) &&
                !((string)old_target->query("id")==(string)obj->query("id")))
                tell_object(old_target, YEL + me->name() + "改变主意不想跟你睡了。\n" NOR);
            me->set_temp("pending/sleep", obj);
            tell_object(obj, YEL "看来" + me->name() +
                "("+(string)me->query("id")+")"+
                "很想跟你．．．如果你愿意，请也下一次 sleep 指令。\n" NOR);
            write(YEL "对方正在考虑中．．．\n" NOR);
            return 1;
        }
        message_vision(RED "\n$N冲着$n会心地一笑，点了点头。\n\n" NOR, me, obj);

        inv = all_inventory(me);
            for(i=0; i<sizeof(inv); i++)
                REMOVE_CMD->do_remove(me, inv[i]);
        inv = all_inventory(obj);
            for(i=0; i<sizeof(inv); i++)
                REMOVE_CMD->do_remove(obj, inv[i]);

        if(me->query("gender")=="男性")
        {
            tell_object(me, HIY "\n\n你搂着"+obj->query("name")+
                "温软的身体，不由得心醉神迷．．．\n\n\n" NOR);
            tell_object(obj, HIY "\n\n你躺在"+me->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        else
        {
            tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得心醉神迷．．．\n\n\n" NOR);
            tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        me->set("last_sleep",time());
        obj->set("last_sleep",time());
        me->set_temp("block_msg/all",1);
        obj->set_temp("block_msg/all",1);
        message_vision(HIY "$N和$n钻入被中，搂在一起睡着了．．．\n\n\n" NOR,me,obj);
        me->disable_player("<睡梦中>");
        obj->disable_player("<睡梦中>");

        call_out("wakeup2",random(15 - me->query("con")) + 0, me,obj, where);
        call_out("wakeup2",random(15 - obj->query("con")) + 0, obj, me,where);
 
        return 1;
}
void wakeup(object me,object where)
{
        object env;
        if(!me) return;
        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        me->add("jingli", me->query("max_jingli")/2 - me->query("jingli")/2 );
        me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
        me->enable_player();
        //客店处理
        if (where->query("temp_hotel"))
                me->delete_temp("rent_paid");
                
        me->delete("no_get");
        me->delete("no_get_from");
        me->delete("no_beg");
        me->delete("no_beg_from");
        me->delete("no_steal");
        me->delete("no_steal_from");
        me->delete_temp("sleeped");  //for sleepbag
        me->set_temp("in_sleeping",0);
        while( environment(me)->is_character() || environment(me)->is_container() )
                me->move(environment(environment(me)));
        env = environment(me);
        me->move(VOID_OB,1);
        me->move(env,1);
        message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
        me->set_temp("block_msg/all", 0);
        write("你一觉醒来，只觉精力充沛。该活动一下了。\n");
        where->add_temp("sleeping_person", -1);
}


int wakeup2(object me,object slept,object where)
{
        int qi_cost;
        object obj, env;

        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
        me->enable_player();
        me->set_temp("in_sleeping",0);
        qi_cost=50+5*((int)me->query("str")-(int)me->query("con"));
        if(qi_cost>(int)me->query("max_qi")/2)
            qi_cost=(int)me->query("max_qi")/2+1;
        me->add("qi", -qi_cost);
        if (me->query("qi") <= 0) me->set("qi", 10);

        while( environment(me)->is_character() || environment(me)->is_container() )
        me->move(environment(environment(me)));
        env = environment(me);
        me->move(VOID_OB,1);
        me->move(env,1);

        if(me->query("gender")=="男性")
        {
            message_vision(HIY "$N醒了过来，似乎还沉浸在幸福之中。\n" NOR,me);
            me->set_temp("block_msg/all", 0);
            write("你醒了过来，似乎还沉浸在幸福之中。\n");
            return 1;
        }
        else
        {
// add bearing function here.
            message_vision(HIY "$N醒了过来，脸上还挂着甜蜜的笑容。\n" NOR,me);
            me->set_temp("block_msg/all", 0);
            write("你醒了过来，脸上还挂着甜蜜的笑容。\n");
            obj=slept;
            //if((int)(me->query("mud_age")/86400) < 6 || (int)(me->query("mud_age")/864000) < me->query("child"))
            if((int)(me->query("mud_age")/86400) < 1 || (int)(me->query("mud_age")/864000) < me->query("child"))
                return 1;
            if (obj!=slept )
            {
                if (!obj || !userp(obj) || !find_player(obj->query("id")))
                {
                    message_vision(HIY "\n$N似乎觉得腹中一阵颤痛，旋即咬咬牙，弯着腰站了起来。\n"NOR, me);
                    write("\n丈夫都不在，怎么也不能把孩子生下来．．．\n");
                } else {
                    message_vision(HIY "\n$N似乎觉得腹中一阵颤痛，旋即羞红着脸，咬咬牙站了起来。\n"NOR, me);
                    write("\n怎么会让他撞上了？．．．\n");
                }
                me->set("neili", me->query("neili")/2);
                me->set("qi", me->query("qi")/2);
                me->set("jing", me->query("jing")/2);
                return 2;
            } else {
                if((int)(me->query("mud_age")/86400) < 1 || (int)(me->query("mud_age")/864000) < me->query("child"))
                {
                    message_vision(HIY "\n$N忽觉腹中一阵颤动，不过马上又平静下来。\n"NOR,me);
                    return 1;
                }
                me->set_temp("is_bearing",1);
                me->start(100);
                obj->start(100);
                message_vision(HIY "\n$N忽觉腹中一阵颤动，赶紧拉住$n的手，柔声说道：要生了! \n" NOR, me,obj);
                call_out("birth1",15,me,obj);
                return 3;
            }
        }
}

int birth1(object me,object obj)
{
    message_vision(HIY "\n$N已是大汗淋漓，一直都在呼天抢地，双手紧紧扣住$n的手不放。\n"+
        "\n婴儿已经探出了头．．．\n"NOR,me,obj);
    call_out("birth2",15,me,obj);
    return 1;
}

void birth2(object me,object obj)
{
    object baby;
    int number;
    message_vision(HIY "\n「哇」．．．，婴儿出世了！\n"+
        "\n$N面色苍白，斜倚在床头，看看孩子满意地露出一丝微笑。\n"NOR, me);
    me->start_busy(1);
    obj->start_busy(1);
    me->set("neili",0);
    me->set("qi",0);
    me->set("jing",0);
    baby=new("/d/taohuacun/npc/baby");
    baby->set("long", baby->query("long")+"这是"+obj->query("name")+"和"+me->query("name")+"的孩子。\n");
    if (random(100)<50)
    {
        baby->set("gender","男性");
        baby->set_name("小"+obj->query("name"),({"xiao "+obj->query("id"),"baby"}));
    }
    else
    {
        baby->set("gender","女性");
        baby->set_name("小"+me->query("name"),({"xiao "+me->query("id"),"baby"}));
    }
    me->add("child",1);
    obj->add("child",1);
    baby->set("parents",({me->query("id"),obj->query("id")}));
    number=me->query("child");
    me->set("child_"+number+"/gender",baby->query("gender"));
    me->set("child_"+number+"/long",baby->query("long"));
    me->set("child_"+number+"/name",baby->query("name"));
    me->set("child_"+number+"/id",({baby->query("id"),"baby"}));
    me->set("child_"+number+"/parents",baby->query("parents"));
    number=obj->query("child");
    obj->set("child_"+number+"/gender",baby->query("gender"));
    obj->set("child_"+number+"/long",baby->query("long"));
    obj->set("child_"+number+"/name",baby->query("name"));
    obj->set("child_"+number+"/id",({baby->query("id"),"baby"}));
    obj->set("child_"+number+"/parents",baby->query("parents"));
    me->delete_temp("is_bearing");
    me->save();
    obj->save();
   //this needs to be put at the last since
   //can only move the baby after it's parameters are set.
    if(!baby->move(environment(me)))
        baby->move(environment(environment(me)));
}
/*
void del_sleeped(object me)
{
        if (objectp(me) &&  me->query_temp("sleeped"))
                me->delete_temp("sleeped");
}
*/
int help(object me)
{
  write(@HELP
指令格式 : sleep <人物>
 
顾名思义，这个指令是用来睡觉的。
HELP
    );
    return 1;
}


