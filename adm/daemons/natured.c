// natured.c
// Modified by Eatdami@MX (10/01/2000)

#define TIME_TICK (time()*24) 

nosave int current_day_phase;
mapping *day_phase;

string *weather_msg = ({
        "�������������",
        "���䵭�����Ʋ�ױ�������ʵ����",
        "�����������Ʈ��Ʈȥ",
        "�����Ʋ�ѻ������",
        "����������ܲ�",
});


mapping *read_table(string file);
int auto_shutdown(int flag);
void init_day_phase();
int backup();

void create()
{
        day_phase = read_table("/adm/etc/nature/day_phase");
        init_day_phase();
}

/*
void autosave(int i)
{

    int  j;
    object *user=children(USER_OB);
    j=i+5;
   for (j=i;j<i+5;j++){
//    if(j>=sizeof(user)) { auto_shutdown(0);  return; }^M
        if (!user[j] || !environment(user[j])) continue;
        user[j]->save();
    tell_object(user[j], HIR "�����̾��顿"+HIY+"��ĵ����Ѿ��Զ��洢�ˡ�\n" NOR);
    }
    call_out("autosave",1,i+5);
}
*/

void init_day_phase()
{
        mixed *local;
        int i, t;

        // Get minutes of today.
        local = localtime(TIME_TICK);
        t = local[2] * 60 + local[1];           // hour * 60 + minutes

        // Find the day phase for now.
        for( i=0; i < sizeof(day_phase); i++)
                if( t >= day_phase[i]["length"] )
                        t -= (int)day_phase[i]["length"];
                else
                        break;

        current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

        // Since in our time scale, 1 minute == 1 second in RL, so we don't need
        // any conversion before using this number as call_out dalay, if you
        // changed the time scale, be sure to convert it.

        call_out("update_day_phase",
      (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
        remove_call_out("update_day_phase");

        current_day_phase = (++current_day_phase) % sizeof(day_phase);
        switch (day_phase[current_day_phase]["outcolor"])
        {
              case "BLK":
                   message("channel:chat", HIG+BLK + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "RED":
                   message("channel:chat", RED + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIR":
                   message("channel:chat", HIR + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "GRN":
                   message("channel:chat", GRN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIG":
                   message("channel:chat", HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "YEL":
                   message("channel:chat", YEL + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIY":
                   message("channel:chat", HIY + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "BLU":
                   message("channel:chat", BLU + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIB":
                   message("channel:chat", HIB + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "MAG":
                   message("channel:chat", MAG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIM":
                   message("channel:chat", HIM + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "CYN":
                   message("channel:chat", CYN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIC":
                   message("channel:chat", HIC + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "WHT":
                   message("channel:chat", WHT + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIW":
                   message("channel:chat", HIW + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              default:
                   message("channel:chat", HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
        }
//        message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
        if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
            call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

        call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}

/*
void event_sunrise()
{
    remove_call_out("autosave");
    call_out("autosave",1,0);
}
*/


void event_midnight()
{
        string get_month;
        get_month = CHINESE_D->chinese_month(TIME_TICK);
        switch(get_month)
        {
                //spring weather
                case "��":
                case "��":
                case "��":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/spring_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/spring_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/spring_wind");
                           break;
                     }
                     break;
                //summer weather
                case "��":
                case "��":
                case "��":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/summer_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/summer_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/summer_wind");
                           break;
                     }
                     break;
                //autumn weather
                case "��":
                case "ʮ":
                case "ʮһ":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/autumn_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/autumn_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/autumn_wind");
                           break;
                     }
                     break;
                //winter weather
                case "ʮ��":
                case "һ":
                case "��":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/winter_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/winter_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/winter_wind");
                           break;
                     }
                     break;
                default:
                     day_phase = read_table("/adm/etc/nature/day_phase");
        }
}


// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase
/*
void event_noon()
{
        object *ob;
        int i, skill,con,con1,con2,con3;
        string get_month,ill,msg;
    remove_call_out("autosave");
    call_out("autosave",1,0);
        get_month = CHINESE_D->chinese_month(TIME_TICK);
        switch(get_month)
        {
                case "��":
                case "��":
                case "��":
                     ill = "kesou";
                     msg = HIG + "��Ȼ��ͷһ���������о��ƺ�Ҫ�����ˡ�\n" + NOR;
                     break;
                case "��":
                case "��":
                case "��":
                     ill = "zhongshu";
                     msg = HIG+"ͻȻ������֮��һ���ڣ��������ˡ�\n" + NOR;
                     break;
                case "��":
                case "ʮ":
                case "ʮһ":
                     ill = "shanghan";
                     msg = HIG+"��������˸���ս��ͷ������ģ�����˺����ˡ�\n"+NOR;
                     break;
                case "ʮ��":
                case "һ":
                case "��":
                     ill = "dongshang";
                     msg = HIG+"��֫��ĩ��һ��ֱ�������㱻�����ˡ�\n"+NOR;
                     break;
        }
        if(random(2))
        {
                ill = "fashao";msg = HIG+"��ż�з纮����������������\n"+NOR;
        }
        ob = users();
        for(i=0; i<sizeof(ob); i++)
        {
                if( !environment(ob[i]) ) continue;
                if( !environment(ob[i])->query("outdoors") ) continue;
                if( ob[i]->query("age")==14 ) continue;
                con1 = ob[i]->query("qi");
                con2 = ob[i]->query("max_qi");
                (int)con = con1/con2*50;//�γɵ�һ�������ж�����
                con3 = ob[i]->query("neili");
                con2 = ob[i]->query("max_neili");
                (int)con1 = con3/con2*50;//�γɵڶ��������ж�����
                if(random(con)+random(50)+random(con1)<25)
                {
                        ob[i]->apply_condition(ill, 10);
                        tell_object(ob[i], msg);
                }
        }
}
*/

string outdoor_room_description()
{
        return "    " + day_phase[current_day_phase]["desc_msg"] + "��\n";
}

int outdoor_room()
{
    if (current_day_phase>5)
    return 1;
}

string game_time()
{
        return CHINESE_D->chinese_date(TIME_TICK);
}

mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;

        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
                        continue;
                }
                break;
        }

        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}

mapping *query_day_phase() { return day_phase; }

/*
int backup()
{
    int i, j, ppl_cnt, count;
    mixed *local;
    string *dir, *ppls, name,data_dir;
    mixed info;

    reset_eval_cost();
  foreach (object userob in children(USER_OB) ){
       if (userob || !environment(userob)) continue;
           userob->save();
    }
    local=localtime(TIME_TICK);
    data_dir="/backdata/back"+local[6]+"/";
    log_file( "AUTOSTART", sprintf("%s autostart!write to %s\n",ctime(time()),data_dir ) );
    count = 0;
    ppl_cnt = 0;
    dir = get_dir(DATA_DIR + "login/");
    for(i=0; i<sizeof(dir); i++) {
        reset_eval_cost();
        ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
        ppl_cnt += sizeof(ppls);
        for(j=0; j<sizeof(ppls); j++) {
            if( sscanf(ppls[j], "%s.o", name)==1 )
                if( (string)SECURITY_D->get_status(name)!="(player)" )
                    continue;
            info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
            if( (time()-(int)info[1])<= 159200 ) {
                assure_file(data_dir + "login/" + dir[i] + "/" + ppls[j]);
                assure_file(data_dir + "user/" + dir[i] + "/" + ppls[j]);
                cp(DATA_DIR + "login/" + dir[i] + "/" + ppls[j],data_dir + "login/" + dir[i] + "/" + ppls[j]);
                cp(DATA_DIR + "user/" + dir[i] + "/" + ppls[j],data_dir + "user/" + dir[i] + "/" + ppls[j]);
                count ++;
            }
        }
    }
    shutdown(0);
    return 1;
}
*/
/*
int auto_shutdown(int flag)
{
    reclaim_objects();
    if (159200-uptime()<=0 || flag){
       message("vision", RED "Ϊ������ٶ�, ϵͳÿ���콫���Զ�崻���\n" NOR, users());
        message("vision", RED "����ģ����ĵ����Ѿ��Զ��洢�ˣ�\n" NOR, users());
        message("system", HIW "\n �Զ�������������У����Ժ�....\n" NOR, users());
        users()->disable_player("����������......");
             call_out("backup",1);
    }
}
*/
