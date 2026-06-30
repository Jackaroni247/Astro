from astroquery.gaia import Gaia
import astropy.units as u
from astropy.coordinates import SkyCoord
from astropy.table import vstack, Table
import numpy as np
import os
import sys
from build import Transformations as TR
import matplotlib.pyplot as plt

LOCAL_DATA_FILE = 'data.vot'
data = None;

#distance in Kilo-parsecs
distance = 1;

#Search at a latitude of 0 and all longitudes
if (not (len(sys.argv)<2)) and (sys.argv[1] == 'query'):
	queryResults = [];
	for l in np.arange(0,360,10.0):
		coord = SkyCoord(l=l * u.deg, b=0 * u.deg, frame='galactic').icrs
		RA = coord.ra.degree
		DEC = coord.dec.degree
		coneRadius = 0.01

		#Calculate info needed for query
		distance = TR.searchDist(l)
		PLAX = 1 / TR.searchDist(90)

		#Queue the coords for the job
		query = f"""
    		SELECT * FROM gaiaDR3.gaia_source
    		WHERE radial_velocity IS NOT NULL
      		AND parallax > {PLAX}
      		AND ra BETWEEN {RA - coneRadius} AND {RA + coneRadius}
      		AND dec BETWEEN {DEC - coneRadius} AND {DEC + coneRadius}
		"""

		job = Gaia.launch_job_async(query)
		queryResults.append(job.get_results())

	#Merge all of the query results into one table
	data = vstack(queryResults);
	data.write(LOCAL_DATA_FILE, format='votable', overwrite=True)
else:
	data = Table.read(LOCAL_DATA_FILE, format='votable');

CelestialObjects = [];
for i in range(len(data)):
	CelestialObjects.append(TR.CelestialObject(TR.Coordinate(0,data[i]["ra"],data[i]["dec"],data[i]["parallax"],data[i]["pmra"],data[i]["pmdec"],data[i]["radial_velocity"])));

print("Celestial Objects Created")
TR.mainProcessing(CelestialObjects);
print("Job Finished")
