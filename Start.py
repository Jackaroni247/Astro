from astroquery.gaia import Gaia
import astropy.units as u
from astropy.coordinates import SkyCoord
from astropy.table import vstack
import numpy as np
from build import Transformations as TR
import matplotlib.pyplot as plt

queryResults = []

#distance in Kilo-parsecs
distance = 1;

#Search at a latitude of 0 and all longitudes
for b in np.arange(0,360,10.0):
	#Convert the GC coords to EQ using the C++ Library
	tempCoord = TR.Coordinate(True,0,b);
	tempCoord.gcTOeq();
	RA = tempCoord.getEQ_RA();
	DEC = tempCoord.getEQ_DEC();
	coord = SkyCoord(ra=RA, dec=DEC, unit=(u.degree, u.degree), frame='icrs')
	coneRadius = 0.5;

	#Calculate info needed for query
	distance = TR.getDist(b);
	PLAX = 1/distance;

	#Queue the coords for the job
	query = "SELECT * FROM gaiaDR3.gaia_source WHERE radial_velocity IS NOT NULL AND parallax > " + str(PLAX) + " AND ra BETWEEN " + str(RA-coneRadius) + " AND " + str(RA+coneRadius) + " AND dec BETWEEN " + str(DEC-coneRadius) + " AND " + str(DEC+coneRadius)
	job = Gaia.launch_job_async(query);
	queryResults.append(job.get_results());

#Merge all of the query results into one table
data = vstack(queryResults);

cvArray = [];
crArray = [];

#Calculate Circular Velocities
for i in range(len(data)):
	star = data[i];
	ra = star['ra'];
	dec = star['dec'];
	pmra = star['pmra'];
	pmdec = star['pmdec'];
	l = star['l'];
	b = star['b'];
	dist = 1/star['parallax'];
	PML = TR.calc_PM_L(ra,dec,pmra,pmdec);
	CV = TR.calcCV(PML,l,b,dist);
	CR = TR.calc_Galactic_Radius(l,b,dist);
	cvArray.append(CV);
	crArray.append(CR);

plt.scatter(crArray, cvArray, color='blue', marker='o');
plt.xlabel('Radius - From Galactic Center');
plt.ylabel('Circular Velocity');
plt.title('Milky Way Galactic Curve');

plt.show();
