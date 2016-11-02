#include <iostream>
#include <time.h>       /* time_t, struct tm, time, gmtime */
#include <mpg123.h>
#include <ao/ao.h>

#define BITS 8
#define UTC (+2)
using namespace std;


void playaudio(const char * trakl)
{

//works when called here including path
const char * traklink=trakl;



   mpg123_handle *mh;
    unsigned char *buffer;
    size_t buffer_size;
    size_t done;
    int err;

    int driver;
    ao_device *dev;

    ao_sample_format format;
    int channels, encoding;
    long rate;

    /* initializations */
    ao_initialize();
    driver = ao_default_driver_id();
    mpg123_init();
    mh = mpg123_new(NULL, &err);
    buffer_size = mpg123_outblock(mh);
    buffer = (unsigned char*) malloc(buffer_size * sizeof(unsigned char));

    /* open the file and get the decoding format */
    //mpg123_open(mh,traklink);
    mpg123_open(mh,traklink);
     mpg123_getformat(mh, &rate, &channels, &encoding);

    /* set the output format and open the output device */
   format.bits = mpg123_encsize(encoding) * BITS;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;
    dev = ao_open_live(driver, &format, NULL);

    /* decode and play */
    while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK)
        //ao_play(dev, buffer, done);
        ao_play(dev, (char*)buffer, done);
    /* clean up */
    free(buffer);
    ao_close(dev);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
    ao_shutdown();

}


int main ()
{
  time_t rawtime;
  struct tm * ptm;

    double hora;
    double minuts;
    //double segons;
    const char * trakl="/home/marc/musica/fricades/1.mp3";

    time ( &rawtime );
    ptm = gmtime ( &rawtime ); //temps

    cout << "Hora actual = " << (ptm->tm_hour+UTC)%24 << " : " <<  ptm->tm_min << endl;
    do{
	cout << "Entra l'hora (00..24)" << endl;
	cin >> hora;
    }while(hora<0 || hora >24);
    do{
        cout << "Entra els minuts (00..59)" << endl;
        cin >> minuts;
    }while(minuts<0 || minuts>59);
    while((ptm->tm_hour+UTC)%24 != hora || ptm->tm_min != minuts){
	    time ( &rawtime );
	    ptm = gmtime ( &rawtime );
	    //cout << "Hora actual = " << (ptm->tm_hour+UTC)%24 << " : " <<  ptm->tm_min << endl;
	    if(((ptm->tm_hour+UTC)%24 == hora) && (ptm->tm_min == minuts)) {
			cout << "Mateixos minuts ?" << ptm->tm_min << " == " << minuts << endl;
			playaudio( trakl);
  		}
	}
  return (0);
}
