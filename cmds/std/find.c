 // find.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void fail(object me);
void find_result(object me, object env, string target);

mapping maps=([]);
void create() 
{ 
   string filename=__DIR__"find.map";
   string buf, *buf1;
   string dir, name;
   int size, i;

   maps=([]);

   buf=read_file(filename);
   if(!buf) return; //no data available.

   buf1=explode(buf,"\n");
   size=sizeof(buf1);
   if(!size) return;

   for(i=0;i<size;i++) {
     if(sscanf(buf1[i],"%s %s",dir,name)==2) {
       name=replace_string(name," ","");
       if(strlen(dir)>2 && strlen(name)>2) {
         maps+=([dir:name]);
       }
     }
   }
}

int main(object me, string target)
{
        object env=environment(me);
//        int mana_cost;
        int i = 10+random(5);

        if (me->is_busy() || me->is_fighting() )
                return notify_fail("你现在正忙着呢。\n");

        if(env->query("no_fight") || env->query("no_magic") )
                return notify_fail("安全区内不能找人。\n");

        if( !target) return notify_fail("你想利用灵魂脱壳寻找谁？\n");
        
        if(me->query_skill("force")<200)
                return notify_fail("你的基本内功不够，无法运用灵魂出壳。\n");

        if((int)me->query("combat_exp")<5000)
                return notify_fail("你的经验不够，无法运用灵魂出壳。\n");
                
        if((int)me->query("jing") < 100||
          (int)me->query("jing")*100/(int)me->query("max_jing")<50 )
                return notify_fail("你现在头晕脑胀，恐怕连自己在哪里都不清楚！\n");

        if((int)me->query("neili") < 100||
          (int)me->query("neili")*100/(int)me->query("max_neili")<50 )
                return notify_fail("你的内力不够，出壳会很危险的。\n");
        
        message_vision(HIB"$N沉思入定开始运用灵魂出壳来定位!!!\n"NOR,me);

        call_out("find_result",i,me,env,target);
        me->start_busy(i);
        return 1;

}

void fail(object me)
{
        tell_object(me,HIW"你自己心理直犯嘀咕：咦？奇怪,难到没这个人存在???\n"NOR);
        return;
}

void find_result(object me, object env, string target)
{
        object ob, where, ling;
        string msg, filename, filename1, answer;
        int len;

        if(!me) return;
        if(environment(me)!=env) return;

        message_vision(HIY
        "只见$N缓缓的站起了身行,灵魂出壳运功完毕。\n" NOR, me);
        
        ob = find_player(target);
        if( !ob ) ob = find_living(target);

        if (!ob || ob->query("env/invisibility")) 
                return fail(me);
        
        where = environment(ob);

        if (!where) return fail(me);

        if(wizardp(me))
                tell_object(me, "Env File :"+base_name(where)+"\n");

        if(random(5) < 2) return fail(me);

        ling = present("yingxiong ling",ob);
        if(objectp(ling) && ling->query("no_find_cmd") == 1){
          tell_object(me,
                  HIG"你自言自语道：人是找到了，但是说不得，不能说．．．\n"NOR+
                  HIM"那家伙带着少林英雄令。\n"NOR);
          return;
        }
        //added by weiqi, need better solution later...

        filename=file_name(where);
        len=strlen(filename);
        if(len<2) return fail(me);

        len--;
        while(filename[len]!='/' && len>0) {
          len--;
        }
        if(len<2) return fail(me);

        filename1=filename[1..(len-1)];

        if(sscanf(filename,"/d/changan/bed#%*s")==1) {
        //this need check first.
          answer="床上";
        } else if(!undefinedp(maps[filename1])) {
          answer=maps[filename1];
        } else if(where->is_character()) {
          answer=where->query("name")+"身上";
        } else if(sscanf(filename,"/obj/home#%*s")==1) {
          answer="住家里";
        } else { 
          answer=undefinedp(where->query("short"))?
                  where->short():
                  where->query("short");
        }

        tell_object(me,WHT"找到了："+(string)ob->name()+
          "("+(string)ob->query("id")+")"+
          "在"+answer+"。\n"NOR);

        message_vision(WHT"$N“啊～～秋～～”一声打了个喷嚏，不由皱了皱眉。\n"NOR,
          ob);
        msg=HIY"你急忙定神敛气，"NOR;
        if(ob->query("combat_exp")>me->query("combat_exp")/3)
          msg+=HIG"隐约感到"+me->name()+"("+me->query("id")+")"+
               "正在利用灵魂脱壳查找你的位置。\n"NOR;
        else
          msg+=HIM"结果是感冒了。\n"NOR;
        tell_object(ob, msg);

        return;
}

int help(object me)
{
        write(@HELP
指令格式 : find <某人>

灵魂脱壳：用来发现别人所在位置。但首先你必须要有较深的内功。
HELP
        );
        return 1;
}
