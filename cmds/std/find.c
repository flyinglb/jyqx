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
                return notify_fail("��������æ���ء�\n");

        if(env->query("no_fight") || env->query("no_magic") )
                return notify_fail("��ȫ���ڲ������ˡ�\n");

        if( !target) return notify_fail("������������ѿ�Ѱ��˭��\n");
        
        if(me->query_skill("force")<200)
                return notify_fail("��Ļ����ڹ��������޷����������ǡ�\n");

        if((int)me->query("combat_exp")<5000)
                return notify_fail("��ľ��鲻�����޷����������ǡ�\n");
                
        if((int)me->query("jing") < 100||
          (int)me->query("jing")*100/(int)me->query("max_jing")<50 )
                return notify_fail("������ͷ�����ͣ��������Լ������ﶼ�������\n");

        if((int)me->query("neili") < 100||
          (int)me->query("neili")*100/(int)me->query("max_neili")<50 )
                return notify_fail("����������������ǻ��Σ�յġ�\n");
        
        message_vision(HIB"$N��˼�붨��ʼ��������������λ!!!\n"NOR,me);

        call_out("find_result",i,me,env,target);
        me->start_busy(i);
        return 1;

}

void fail(object me)
{
        tell_object(me,HIW"���Լ�����ֱ���ֹ����ף����,�ѵ�û����˴���???\n"NOR);
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
        "ֻ��$N������վ��������,�������˹���ϡ�\n" NOR, me);
        
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
                  HIG"������������������ҵ��ˣ�����˵���ã�����˵������\n"NOR+
                  HIM"�Ǽһ��������Ӣ���\n"NOR);
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
          answer="����";
        } else if(!undefinedp(maps[filename1])) {
          answer=maps[filename1];
        } else if(where->is_character()) {
          answer=where->query("name")+"����";
        } else if(sscanf(filename,"/obj/home#%*s")==1) {
          answer="ס����";
        } else { 
          answer=undefinedp(where->query("short"))?
                  where->short():
                  where->query("short");
        }

        tell_object(me,WHT"�ҵ��ˣ�"+(string)ob->name()+
          "("+(string)ob->query("id")+")"+
          "��"+answer+"��\n"NOR);

        message_vision(WHT"$N�������������һ�����˸����磬����������ü��\n"NOR,
          ob);
        msg=HIY"�㼱æ����������"NOR;
        if(ob->query("combat_exp")>me->query("combat_exp")/3)
          msg+=HIG"��Լ�е�"+me->name()+"("+me->query("id")+")"+
               "������������ѿǲ������λ�á�\n"NOR;
        else
          msg+=HIM"����Ǹ�ð�ˡ�\n"NOR;
        tell_object(ob, msg);

        return;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : find <ĳ��>

����ѿǣ��������ֱ�������λ�á������������Ҫ�н�����ڹ���
HELP
        );
        return 1;
}
