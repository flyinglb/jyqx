//modified by wind

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
        } else result = look_room_item(me, arg);

        return result;
}

int look_room(object me, object env)
{
        int i,amount;
        object *inv;
        mapping exits,my;
        string str, *dirs;

        if( !env ) {
                if( !me->force_move_to_void() ) {
                        write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
                        return 1;
                } else env = environment(me);
        }
//      str = sprintf( "%s - %s\n    %s%s",
        str = sprintf(HIG + "�� " + NOR  + HIR + "%s" + NOR + HIG + " ��" + NOR  +  " - %s\n    %s%s",
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                        str += "    ����û���κ����Եĳ�·��\n";
                else if( sizeof(dirs)==1 )
                        str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
                else
                        str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
                                implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
        }
//      str += env->door_description();

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( !me->visible(inv[i]) ) continue;
                if(inv[i]->query("hide")) continue;

     if (inv[i]->query("money_id") || !inv[i]->query("unit")            || inv[i]->is_character()){  
     str+=sprintf("    %s\n",inv[i]->short()); 
           continue;        }
     if (!mapp(my))            my=([inv[i]->query("unit")+inv[i]->short():1]);        else{            amount=my[inv[i]->query("unit")+inv[i]->short()];            my[inv[i]->query("unit")+inv[i]->short()]=amount+1;        
         }    
     }     if(mapp(my)){     
     dirs=keys(my);   
     for(i=0;i<sizeof(my);i++)
     str+=sprintf("%s%s\n",my[dirs[i]]==1?"":CHINESE_D->chinese_number(my[dirs[i]]),my[dirs[i]]==1?dirs[i][2..]:dirs[i]);    
     }  

     write(str);
     return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;

    if (!me->visible(obj)) { write("��Ҫ��ʲô��\n"); return 1; }
      me->start_more(obj->long());
        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("�����У�\n  %s\n",
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}

int look_living(object me, object obj)
{
        string str, pro;
        mixed *inv;
        mapping my_fam, fam;
        int per,i;
        int me_shen, obj_shen;

        if( me!=obj )
                message("vision", me->name() + "�������㿴����֪����Щʲô���⡣\n", obj);

        str = obj->long();

        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

        if( (string)obj->query("race")=="����"
        &&      intp(obj->query("age")) )
                str += sprintf("%s������Լ%s���ꡣ\n", pro, chinese_number((obj->query("age") - obj->query("lessage")) / 10 * 10));
        per = obj->query_per(); 
        if (per>9) {      
        if ((string) obj->query("gender") == "����" || (string) obj->query("gender") == "����")
        {
                if (per >= 30)
                  {     i=random(2);
                        if (i==0)
                        str += pro+"ò���˰����Կ�������������Լ����̬�����������Σ�\n"
                                   "������ü֮�е�һ�ˡ�\n";
// look.c
                        if (i==1)
                        str += pro+"���տ��Σ���ɷ��������ǧ��������Ů�·�����\n";
                  }
                if ((per >= 27) && (per < 30))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"�����ٷ磬�������Σ���֪���˶���Ů���ɡ�\n";
                        if (i==1)
                        str += pro+"������ȣ��������ԣ�������ˣ������Ƿ���\n";
                        if (i==2)
                        str += pro+"�ݹ����ˣ������ޱȣ�������Ϊ����ת����\n";
                  }
                if ((per >= 24) && (per < 27))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"������ˮ��̬�����ƣ��Ǳ����á�\n";
                        if (i==1)
                        str += pro+"�����Ũ������֮���٣���֮��Ϊ�������·���\n";
                  }
                if ((per >= 22) && (per < 24))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"���θߴ������忡��˫�����񣬲�ŭ������\n";
                        if (i==1)
                        str += pro+"������ͬ��ӥ���ж����缲�磬�����ķ���\n";
                  }
                if ((per >= 20) && (per < 22))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"���ο��࣬�����ᣬ�������棬�������͡�\n";
                        if (i==1)
                        str += pro+"�����������������ƣ��������죬һ���ú���\n";
                  }
                if ((per >= 18) && (per < 20))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"�����ģ���òƽƽ�����ް�����֮����\n";
                        if (i==1)
                        str += pro+"ʵ���Ǹ�Ѱ��֮�ˣ�����Ⱥ��һվ����Ҳ�޴���Ѱ��\n";
                  }
                if ((per >= 15) && (per < 18))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"����������ʨ���ɴ����������⣬��ò���硣\n";
                        if (i==1)
                        str += pro+"�����ͷ��Ŀ����ü����Ȧ�ȶ����ͱ���\n"
                                   "���Ƴ��ˣ����ನƤ������\n";
                  }
                if (per < 15)
                  {     i=random(2);
                        if (i==0)
                        str += pro+"��ò�׳��ռ�����ɷ����࣬���ײ�Ͼ�Ϊ���\n";
                        if (i==1)
                        str += pro+"���ò�����Ŀ��ʵ�����϶Բ����죬�¶Բ���أ�\n"
                                   "���Բ�����ע������������\n";
                  }
        }
        else
        {
            if ((string) obj->query("gender") == "Ů��")
            {
                if (per >= 30)
                  {     i=random(3);
                        if (i==0)
                        str += pro+"��ֻ���������ʶ��������磬΢���촽����������\n"
                                   "�������ƶ����������������˼�����֮��ɫ��\n";
                        if (i==1)
                        str += pro+"���˹�ɫ�������徣���۴��е�һ�ˡ���ʫΪ֤��\n"
                                   "�����ԭӦ�����У������������˼䡱��\n";
                        if (i==2)
                        str += pro+"��ɫ���㣬������ɣ������޹ǣ�����ʤ�գ�\n"
                                   "�Ƕ��ٶ��ɰ��������顭��\n";
                  }
                if ((per >= 27) && (per < 30))
                  {     i=random(4);
                        if (i==0)
                        str += pro+"��ֻ���촽��������ͬ����֮����ü���Ƕ�������\n"
                                   "�ź����Ӷ���򭣬�ﲨת��������Ʈ����\n";
                        if (i==1)
                        str += pro+"�����Σ��۾��������������������ɣ����ӯӯʹ����ϧ��\n"
                                   "�������Բ�����Ŀ����������ý��������������˾찮��\n";
                        if (i==2)
                        str += pro+"��������һ�����Ө��ͬ����˫�ǲ������۲�������\n"
                                   "�粽δ�ƶ����ݺ�ת��������ꡣ\n";
                       if (i==3)
                        str += pro+"ٻӰ�������Ʋ����㣬��ɫ��֮������֮�ý���Ҳ��\n";
                  }
                if ((per >= 24) && (per < 27))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"��ͬ������̬�����У������׿����־���ѣ�����\n"
                                   "װ����Ũ��֮�ʣ���̬�ӷ���֮�䡣\n";
                        if (i==1)
                        str += pro+"ɫ�������̬�����գ��᲻���ۣ�ӯӯ�������ϣ�\n"
                                   "�������⣬����ٲ�ڻ��С�\n";
                        if (i==2)
                        str += pro+"������翣���������δ�棬������У����º������£�\n"
                                   "��һ��Ȼ֮����Ҳ��\n";
                  }
                if ((per >= 22) && (per < 24))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"���ս��ã�ü���죬��������������ӣ�����޽��ɡ�\n";
                        if (i==1)
                        str += pro+"����Ц���绨������С�ɣ����ǿ��ˡ�\n";
                        if (i==2)
                        str += pro+"�����ǡ������ö���Ц����������ʮ�ֶ��ˡ�\n";
                  }
                if ((per >= 20) && (per <22))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"�����񻣬�������涼���Ρ���ɷ�ǿɰ���\n";
                        if (i==1)
                        str += pro+"�����ǡ���ü˳�������ż¶Ц�������ɡ���\n";
                        if (i==2)
                        str += pro+"΢Ц¶�׳ݣ�����͸�࣬��Ƥ���ˡ�����\n";
                  }
                if ((per >= 18) && (per <20))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"��ɫѰ������ҲЦ̬�ɾϣ����ù�ȥ��\n";
                        if (i==1)
                        str += pro+"���ν�˶����̬���ȣ�����һ����ɡ�\n";
                        if (i==2)
                        str += pro+"װ���嵭����ʩ���ֵ�ױ����Ҳ����������ɫ������\n";
                  }
                if ((per >= 16) && (per <18))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"������һ�㲻�����о�����ƽ�����������������ۡ�\n";
                        if (i==1)
                        str += pro+"��òƽƽ���������Ů�Ӻ�ֹǧ��������ˡ�\n";
                  }
                if ((per >= 14) && (per <16))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"�����ǡ�����ͷ���������ֻ�´����ѳ��ޡ���\n";
                        if (i==1)
                        str += pro+"��ĸߴ󣬱������𣬵�������ӡ�\n";
                        if (i==2)
                        str += pro+"��������ˮͰ�����ƾ�����Բ�������ò��ѿ�������\n";
                  }
                if (per <14)
                  {     i=random(3);
                        if (i==0)
                        str += pro+"��ò��������է����������ţ�ϸ�۽�����ɲ��\n"
                                   "���������˼��һ�󸾡�\n";
                        if (i==1)
                        str += pro+"�������Σ�������Ҫ���ʣ������ٶ࿴һ�ۣ�\n";
                        if (i==2)
                        str += pro+"���úó�������̬��ɥ�����߷ֲ������ˣ�\n"
                                   "������������»��������ˡ�\n";
                  }
            }
            else  str += pro+"ֻ��һֻ�������ѣ�����������ģ���ˡ�\n";
        }
        }
        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family")) 
        &&      fam["family_name"] == my_fam["family_name"] ) {
        
                if( fam["generation"]==my_fam["generation"] ) {
                        if( (string)obj->query("gender") == "����" ||
                                (string)obj->query("gender") == "����")
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        else
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "�����ʦ����\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "�����ͬ�ų�����\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "�����ʦ����\n";
                        else
                                str += pro + "�����ʦ�塣\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "�����ͬ������\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "����ĵ��ӡ�\n";
                        else
                                str += pro + "�����ʦֶ��\n";
                }
        }

        if( obj->query("max_qi") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s���ϴ�����\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me && living(obj)
        && (((me_shen < 0) && (obj_shen > 0)) || ((me_shen > 0) && (obj_shen < 0)))
        && (((me_shen - obj_shen) > ((int)obj->query("neili") * 20))
        || ((obj_shen - me_shen) > ((int)obj->query("neili") * 20))))
        {
                write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
                if(obj->query("age") > 15 && me->query("age") > 15)
                        COMBAT_D->auto_fight(obj, me, "berserk");
        }
        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = HIC "  ��" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                        
                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("��Ҫ��ʲô��\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
        return 1;
}


